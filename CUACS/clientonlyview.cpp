#include "clientonlyview.h"
#include "ui_clientonlyview.h"

ClientOnlyView::ClientOnlyView(QMainWindow *lg, Client *c, databaseManager* db,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientOnlyView)
{
    login = lg;

    ui->setupUi(this);
      
    databaseManager *localDB = db;
    cm = ClientManager(localDB);
    am = AnimalManager(localDB);

    view = new AnimalDetailedView(&(am), ui->animalTbl,false);

    fName = c->getFirstName();
    lName = c->getLastName();
    user = c->getUsername();

    //These connect() calls link the signal, with the slot, passing the same parameters between each function.
    //Whenever the signal occurs, the function that is set as the slot will be called.
    connect(ui->actionLog_Out, SIGNAL(triggered()), this, SLOT(logout()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitFunc()));

    //Populate the animal table
    animalNum = 1;
    ui->animalTbl->setRowCount(am.getAnimals().size());
    for(unsigned int i = 0;i< am.getAnimals().size();i++){
        displayNewAnimal(am.getAnimals()[i],i+1);
    }

    //Set up the values for the provinces combo box
    QString provinces[] = {"BC", "AB", "SK", "MB", "ON", "QC", "NL", "NB","NU","NS", "NT","PE", "YT"};
    for(int i = 0;i<13; i++){
        ui->provinceCombo->insertItem(i,provinces[i]);
        if (c->getProvince() == provinces[i]){
            ui->provinceCombo->setCurrentIndex(i);
        }
    }

    //Set up the display values
    ui->socSpin->setValue(c->getSociability());
    ui->trainSpin->setValue(c->getOwnerControl());
    ui->tempSpin->setValue(c->getBehaviour());

    if(c->getSocialRank()==1){
        ui->socRank->setCurrentIndex(0);
    }else if (c->getSocialRank()==2){
        ui->socRank->setCurrentIndex(1);
    }else if (c->getSocialRank()==3){
        ui->socRank->setCurrentIndex(2);
    }else{
        ui->socRank->setCurrentIndex(3);
    }

    if(c->getBehaveRank()==1){
        ui->tempRank->setCurrentIndex(0);
    }else if (c->getBehaveRank()==2){
        ui->tempRank->setCurrentIndex(1);
    }else if (c->getBehaveRank()==3){
        ui->tempRank->setCurrentIndex(2);
    }else{
        ui->tempRank->setCurrentIndex(3);
    }

    if(c->getOwnerRank()==1){
        ui->trainRank->setCurrentIndex(0);
    }else if (c->getOwnerRank()==2){
        ui->trainRank->setCurrentIndex(1);
    }else if (c->getOwnerRank() == 3){
        ui->trainRank->setCurrentIndex(2);
    }else{
        ui->trainRank->setCurrentIndex(3);
    }

    if(c->getChildFriendly() == 1){
        ui->notFriendlyChild->setChecked(true);
    }else if (c->getChildFriendly() == 2){
        ui->noChildPreference->setChecked(true);
    }else{
        ui->childFriendly->setChecked(true);
    }

    if(c->getStrangerFriendly() == 1){
        ui->notFriendlyStrange->setChecked(true);
    }else if (c->getStrangerFriendly() == 2){
        ui->noStrangePreference->setChecked(true);
    }else{
        ui->strangeFriend->setChecked(true);
    }

    ui->firstName->setText(c->getFirstName());
    ui->lastName->setText(c->getLastName());
    ui->user->setText(c->getUsername());
    ui->passwordTxt->setText(c->getPassword());
    ui->emailTxt->setText(c->getEmail());
    ui->postalCodeTxt->setText(c->getPostalCode());
    ui->cityTxt->setText(c->getCity());
    ui->addressLine1Txt->setText(c->getAddressLine1());
    ui->addressLine2Txt->setText(c->getAddressLine2());
    ui->phoneTxt->setText(c->getPhoneNumber());

    connect(ui->animalTbl,SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(setSelectedAnimal(int,int,int,int)));
}

ClientOnlyView::~ClientOnlyView()
{
    delete ui;
}

/**
Function: logout()
in:
out:
return:
purpose: Close the current view, and return to the login screen
**/
void ClientOnlyView::logout(){
    login->show();
    this->close();
}

/**
Function: exitFunc()
in:
out:
return:
purpose: Close the program
**/
void ClientOnlyView::exitFunc(){
    this->close();
}

/**
Function: displayNewAnimal()
in: Animal newAnimal, int rowNum
out:
return:
purpose: Display the given animal on the table, at the given row
**/
void ClientOnlyView::displayNewAnimal(Animal newAnimal, int rowNum){
    int row = rowNum;
    ui->animalTbl->setRowCount(row);
    ui->animalTbl->setCellWidget(row-1,0,new QLabel(newAnimal.getName()));
    ui->animalTbl->setCellWidget(row-1,1,new QLabel(newAnimal.getSpecies()));
    ui->animalTbl->setCellWidget(row-1,2,new QLabel(newAnimal.getBreed()));
    ui->animalTbl->setCellWidget(row-1,3,new QLabel(newAnimal.getGender()));
    ui->animalTbl->setCellWidget(row-1,4,new QLabel(newAnimal.getDOB()));
    ui->animalTbl->setCellWidget(row-1,5,new QLabel(QString::number(newAnimal.getYears()) + "/" + QString::number(newAnimal.getMonths())));
    QLabel *vaccinated;
    if(newAnimal.isVaccinated()){
        vaccinated = new QLabel("Yes");
    }else{
        vaccinated = new QLabel("No");
    }
    ui->animalTbl->setCellWidget(row-1,6,vaccinated);
    animalNum+=1;
}

/**
Function: on_pushButton_clicked()
in:
out:
return:
purpose: display the detailed animal view
**/
void ClientOnlyView::on_pushButton_clicked()
{
    view->setAnimals();
    view->show();
}

/**
Function: setSelectedAnimal()
in: int row, int _x, int _y, int _z
out:
return:
purpose: sets the index of the detailed Animal view, based on the current selected row in the table
NOTE: Due to the function of slots and signals, this function must have the same number of parameters
as the signal that calls it, despite only needing to use the one parameter for the row.
**/
void ClientOnlyView::setSelectedAnimal(int row, int _x, int _y, int _z){
    view->setIndex(row);
}


/**
Function: on_editClientBtn_clicked()
in:
out:
return:
purpose: Handle getting and validating the edited values from the edit client page
**/
void ClientOnlyView::on_editClientBtn_clicked()
{

    QString postal, pass, town, prov, mail, addLn1, addLn2, phone, confirmPass;
    bool allFull = true;
    int pos = 0;

    //Set up the RegExp validators, and get the information from the page
    QRegExp textNoSpaces("^[a-zA-Z]*$");
    QRegExpValidator validateTextOnly(textNoSpaces);
    QRegExp postalRegex("^([A-Za-z]\\d[A-Za-z][-]?\\d[A-Za-z]\\d)");
    QRegExpValidator postalValidator(postalRegex);
    postal = ui->postalCodeTxt->text();
    QRegExp passRegex("^[a-zA-Z0-9]*$");
    QRegExpValidator validatePassword(passRegex);
    pass = ui->passwordTxt->text();
    confirmPass = ui->confirmPasswordTxt->text();
    town = ui->cityTxt->text();
    prov = ui->provinceCombo->currentText();
    mail = ui->emailTxt->text();
    QRegExp emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    emailRegex.setCaseSensitivity(Qt::CaseInsensitive);
    emailRegex.setPatternSyntax(QRegExp::RegExp);
    QRegExpValidator emailValid(emailRegex);
    addLn1 = ui->addressLine1Txt->text();
    addLn2 = ui->addressLine2Txt->text();
    QRegExp phoneRegex("\\(\\d\\d\\d\\)-\\d\\d\\d-\\d\\d\\d\\d");
    QRegExpValidator phoneValidator(phoneRegex);
    phone = ui->phoneTxt->text();

    QString errorString = "";

    //These if statements will validate each string, and update a boolean
    //to keep track of whether there are any errors, as well as updating
    //the logs.
    if(postalValidator.validate(postal,pos)!=Acceptable||postal==""){
        ui->emptyClientLbl->setHidden(false);
        errorString += "Postal code must be of the format: A1A1A1\n";
        allFull = false;
    }
    if(pass!=confirmPass){
        ui->passConLbl->setHidden(false);
        errorString += "Both passwords must match.\n";
        allFull = false;
    }else{
        ui->passConLbl->setHidden(true);
    }
    if(validatePassword.validate(pass,pos)!=Acceptable||pass==""){
        errorString += "Please ensure your password only contains alphanumeric characters.\n";
        ui->emptyClientLbl->setHidden(false);
        allFull = false;

    }
    if(validateTextOnly.validate(town,pos)!=Acceptable||town==""){
        errorString += "Please ensure that the city you entered only contains alphabetic characters.\n";
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(emailValid.validate(mail,pos) != Acceptable||mail==""){
        errorString += "Please ensure you entered a valid email address.\n";
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if (prov ==""){
        errorString += "Please select a province.\n";
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(addLn1 == ""){
        errorString += "Please enter your address.\n";
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(phoneValidator.validate(phone,pos)!=Acceptable||phone==""){
       errorString += "Please ensure your phone number is in the format: (xxx)-xxx-xxxx.\n";
       ui->emptyClientLbl->setHidden(false);
       allFull = false;
    }

    //Get and store the values from the radio buttons
    int ownCon = ui->trainSpin->value();
    int ownRank;
    QString oR = ui->trainRank->currentText();
    if(oR=="1"){
        ownRank = 1;
    }else if (oR=="2"){
        ownRank = 2;
    }else if(oR == "3"){
        ownRank = 3;
    }else{
        ownRank = 4;
    }
    int socab = ui->socSpin->value();
    int socRank;
    QString sR = ui->socRank->currentText();
    if(sR == "1"){
        socRank = 1;
    }else if (sR == "2"){
        socRank = 2;
    }else if (sR == "3"){
        socRank = 3;
    }else{
        socRank = 4;
    }
    int behav = ui->tempSpin->value();
    int behavRank;
    QString behave = ui->tempRank->currentText();
    if(behave == "1"){
        behavRank = 1;
    }else if (behave == "2"){
        behavRank = 2;
    }else if (behave == "3"){
        behavRank = 3;
    } else{
        behavRank = 4;
    }
    int strangeFriend;
    int childFriend;

    if(ui->notFriendlyChild->isChecked()){
        childFriend = 1;
    }else if(ui->noChildPreference->isChecked()){
        childFriend = 2;
    }else if (ui->childFriendly->isChecked()){
        childFriend = 3;
    }

    if(ui->notFriendlyStrange->isChecked()){
        strangeFriend = 1;
    }else if (ui->noStrangePreference->isChecked()){
        strangeFriend = 2;
    } else if(ui->strangeFriend->isChecked()){
        strangeFriend = 3;
    }

    //if there are no errors, add the client, otherwise display what errors there are
    if(allFull){
       errorInformation *e = new errorInformation("Changes saved!");
       e->show();
      Client temp = cm.addClient(fName,lName,postal,town,prov,user,mail,pass,phone,addLn1,addLn2, ownCon, ownRank, socab, socRank,behav, behavRank,strangeFriend, childFriend);
    }else{
        errorInformation *e = new errorInformation(errorString);
        e->show();
    }
}
