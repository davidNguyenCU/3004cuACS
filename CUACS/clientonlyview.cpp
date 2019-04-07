#include "clientonlyview.h"
#include "ui_clientonlyview.h"

ClientOnlyView::ClientOnlyView(Client *c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientOnlyView)
{
    ui->setupUi(this);
    databaseManager *localDB = new databaseManager("localStorage.db");
    localDB->createTable();
    //localDB->populateTables();
    cm = ClientManager(localDB);
    am = AnimalManager(localDB);

    //QString fName = currentClient->getFirstName();
    //QString lName = currentClient->getLastName();
    //QString user = currentClient->getUsername();
    fName = c->getFirstName();
    lName = c->getLastName();
    user = c->getUsername();

    animalNum = 1;
    ui->animalTbl->setRowCount(am.getAnimals().size());
    for(unsigned int i = 0;i< am.getAnimals().size();i++){
        displayNewAnimal(am.getAnimals()[i],i+1);
    }

    QString provinces[] = {"BC", "AB", "SK", "MB", "ON", "QC", "NL", "NB","NU","NS", "NT","PE", "YT"};
    for(int i = 0;i<13; i++){
        ui->provinceCombo->insertItem(i,provinces[i]);
        if (c->getProvince() == provinces[i]){
            ui->provinceCombo->setCurrentIndex(i);
        }
    }
    QString ranks[] = {"1","2","3", "No preference."};
    for (int i = 0;i<4;i++){
        ui->tempRank->insertItem(i, ranks[i]);
        ui->socRank->insertItem(i, ranks[i]);
        ui->trainRank->insertItem(i, ranks[i]);
    }
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

}

ClientOnlyView::~ClientOnlyView()
{
    delete ui;
}

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

void ClientOnlyView::on_pushButton_clicked()
{
    AnimalDetailedView *view = new AnimalDetailedView(am, ui->animalTbl,false);
    view->setAnimals();
    view->show();
}

void ClientOnlyView::on_editClientBtn_clicked()
{

    QString postal, pass, town, prov, mail, addLn1, addLn2, phone, confirmPass;
    bool allFull = true;
    int pos = 0;
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


    if(postalValidator.validate(postal,pos)!=Acceptable||postal==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;

    }
    if(pass!=confirmPass){
        ui->passConLbl->setHidden(false);
    }else{
        ui->passConLbl->setHidden(true);
    }
    if(validatePassword.validate(pass,pos)!=Acceptable||pass==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;

    }
    if(validateTextOnly.validate(town,pos)!=Acceptable||town==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(emailValid.validate(mail,pos) != Acceptable||mail==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if (prov ==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(addLn1 == ""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(phoneValidator.validate(phone,pos)!=Acceptable||phone==""){
       ui->emptyClientLbl->setHidden(false);
       allFull = false;
    }

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


    if(true){
        //clients.push_back(manageClients.addClient(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2));
      Client temp = cm.addClient(fName,lName,postal,town,prov,user,mail,pass,phone,addLn1,addLn2, ownCon, ownRank, socab, socRank,behav, behavRank,strangeFriend, childFriend);

    }
}
