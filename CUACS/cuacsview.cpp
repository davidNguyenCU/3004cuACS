#include "cuacsview.h"
#include "ui_cuacsview.h"
#include "ACM.h"
using namespace std;

//Constructor for the CUACSView, initializes all on screen items properly
CUACSView::CUACSView(databaseManager* db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUACSView)
{
    ui->setupUi(this);
    clientNum = 1;
    animalNum = 1;
    databaseManager *localDB = db;
    manageClients = ClientManager(localDB);
    manageAnimals = AnimalManager(localDB);
    detailedView = new DetailedClientView();
    animalView = new AnimalDetailedView(manageAnimals,ui->animalTbl, true);

    connect(ui->clientTable,SIGNAL(currentCellChanged(int,int,int,int)),this, SLOT(setSelectedClient(int, int, int, int)));
    connect(ui->animalTbl, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(setSelectedAnimal(int, int, int, int)));

    animals = manageAnimals.getAnimals();
    clients = manageClients.getClients();

    ui->genderCombo->insertItem(0, "Male");
    ui->genderCombo->insertItem(1,"Female");
    QString species[] = {"Dog","Cat","Bird","Turtle","Frog","Hamster","Guinea Pig"};
    for(int i = 0;i<7; i++){
        ui->speciesCombo->insertItem(i,species[i]);
    }

    QString provinces[] = {"BC", "AB", "SK", "MB", "ON", "QC", "NL", "NB","NU","NS", "NT","PE", "YT"};
    for(int i = 0;i<13; i++){
        ui->provinceCombo->insertItem(i,provinces[i]);
    }

    ui->speciesCombo->setCurrentIndex(-1);
    ui->genderCombo->setCurrentIndex(-1);
    ui->provinceCombo->setCurrentIndex(-1);
    ui->emptyAnimalLbl->setHidden(true);
    ui->emptyClientLbl->setHidden(true);
    ui->passConLbl->setHidden(true);

    ui->animalTbl->setRowCount(animals.size());
    for(unsigned int i = 0;i< animals.size();i++){
        displayNewAnimal(animals[i],i+1);
    }
    ui->clientTable->setRowCount(clients.size());
    for(unsigned int i = 0;i< clients.size();i++){
        displayNewClient(clients[i],i+1 );
    }
    ui->ACM_table->setRowCount(clients.size());
    for(unsigned int i = 0;i< clients.size();i++){
        displayNewClient(clients[i],i+1 );
    }
}

//destructor for CUACSView
CUACSView::~CUACSView()
{
    delete detailedView;
    delete animalView;
    delete ui->speciesCombo;
    delete ui->label_8;
    delete ui->horizontalLayout_6;
    delete ui->vaccinatedChk;
    delete ui->label_6;
    delete ui->genderCombo;
    delete ui->horizontalLayout_4;
    delete ui->yearsSpn;
    delete ui->monthsSpn;
    delete ui->label_5;
    delete ui->label_4;
    delete ui->label_3;
    delete ui->horizontalLayout_3;
    delete ui->verticalLayout_2;
    delete ui->label_7;
    delete ui->DOBTxt;
    delete ui->horizontalLayout_5;
    delete ui->label_2;
    delete ui->breedTxt;
    delete ui->horizontalLayout_2;
    delete ui->nameTxt;
    delete ui->label;
    delete ui->horizontalLayout;
    delete ui->verticalLayout;
    delete ui->horizontalLayout_13;
    delete ui->emptyAnimalLbl;
    delete ui->addAnimalBtn;
    delete ui->tab_2;
    delete ui->animalTbl;
    delete ui->tab;
    delete ui->centralWidget;
    delete ui->statusBar;
    delete ui;
}

/**
Function: displayNewAnimal(Animal, int)
in: Animal newAnimal to be displayed in the GUI, int rownum to set where to place the newly added animal
out:
return:
purpose: Display a newly added Animal to the animalTbl, for listing all animals
**/
void CUACSView::displayNewAnimal(Animal newAnimal, int rowNum){
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
Function: displayNewAnimal(Animal, int)
in: Animal newAnimal to be displayed in the GUI, int rownum to set where to place the newly added animal
out:
return:
purpose: Display a newly added Animal to the animalTbl, for listing all animals
**/
void CUACSView::editDisplayedAnimal (Animal newAnimal, int row){

    ui->animalTbl->setCellWidget(row,0,new QLabel(newAnimal.getName()));
    ui->animalTbl->setCellWidget(row,1,new QLabel(newAnimal.getSpecies()));
    ui->animalTbl->setCellWidget(row,2,new QLabel(newAnimal.getBreed()));
    ui->animalTbl->setCellWidget(row,3,new QLabel(newAnimal.getGender()));
    ui->animalTbl->setCellWidget(row,4,new QLabel(newAnimal.getDOB()));
    ui->animalTbl->setCellWidget(row,5,new QLabel(QString::number(newAnimal.getYears()) + "/" + QString::number(newAnimal.getMonths())));
    QLabel *vaccinated;
    if(newAnimal.isVaccinated()){
        vaccinated = new QLabel("Yes");
    }else{
        vaccinated = new QLabel("No");
    }
    ui->animalTbl->setCellWidget(row-1,6,vaccinated);

}

/**
Function: displayNewClient(Client, int)
in: Client newClient to be displayed in the GUI, int rownum to set where to place the newly added Client
out:
return:
purpose: Display a newly added Client to the clientTbl, for listing all clients
**/
void CUACSView::displayNewClient(Client newClient, int rowNum){
    int row = rowNum;
    ui->clientTable->setRowCount(row);
    ui->clientTable->setCellWidget(row-1,0,new QLabel(newClient.getUsername()));
    ui->clientTable->setCellWidget(row-1,1,new QLabel(newClient.getFirstName()));
    ui->clientTable->setCellWidget(row-1,2,new QLabel(newClient.getLastName()));
    ui->clientTable->setCellWidget(row-1,3,new QLabel(newClient.getEmail()));
    ui->clientTable->setCellWidget(row-1,4,new QLabel(newClient.getPhoneNumber()));
    clientNum += 1;
}

/**
Function: displayACMResults(vector<std::pair<Client, Animal>>)
in: vector of <Client, Animal> pairs, to be displayed in ACM tab
out:
return:
purpose: Display ACM results to ACM_table, for listing all client and animal pairs.
**/
void CUACSView::displayACMResults(vector<std::pair<Client, Animal>> animalClientPairs){
    for(uint i = 0; i < animalClientPairs.size(); i++){
        std::pair<Client, Animal> currentPair = animalClientPairs.at(i);
        float compatibilityIndex = ACM::getCompatibilityIndex(currentPair.second, currentPair.first);
        int compatibilityPercent = (int)(compatibilityIndex * 100.0f);

        ui->ACM_table->setCellWidget(i, 0, new QLabel(currentPair.first.getFirstName() + " " + currentPair.first.getLastName()));
        ui->ACM_table->setCellWidget(i, 1, new QLabel(currentPair.second.getName() + ", " + currentPair.second.getBreed()));
        ui->ACM_table->setCellWidget(i, 2, new QLabel(QString::number(compatibilityPercent) + "%"));
        //ui->ACM_table->setCellWidget(i, 2, new QLabel());
        //ui->ACM_table->setCellWidget(i, 3, new QLabel());

    }
}

/**
Function: on_addAnimalBtn_clicked()
in:
out:
return:
purpose: Handle adding a new animal to the database and updating the display as a new animal is added.
**/
//Change this function to pass information to the animalManagementClass
void CUACSView::on_addAnimalBtn_clicked()
{
    QString name = ui->nameTxt->text();
    QString breed = ui->breedTxt->text();
    QString species = ui->speciesCombo->currentText();
    QString DOB = ui->DOBTxt->text();
    QString gender = ui->genderCombo->currentText();

    QRegExp breedRegEx("^[a-zA-Z][a-zA-Z\\s]*$");
    QRegExpValidator breedValidator(breedRegEx);
    //format yyyy-mm-dd
    QRegExp DOBRegEx("\\d\\d\\d\\d-\\d\\d-\\d\\d");
    QRegExpValidator DOBValidator(DOBRegEx);
    bool vaccinated = ui->vaccinatedChk->checkState();
    int ageYears = ui->yearsSpn->value();
    int ageMonths = ui->monthsSpn->value();
    int pos = 0;

    int temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfulness, patience, independence, obedience;
    temperament = ui->temperamentSpin->value();
    trainability = ui->trainabilitySpin->value();
    intelligence = ui->intelligenceSpin->value();
    mischievousness = ui->mischievousnessSpin->value();
    socialAttitude = ui->animalFriendlySpin->value();
    strangerFriendly = ui->friendlyStrangerSpin->value();
    energy = ui->energySpin->value();
    childFriendly = ui->childFriendlySpin->value();
    playfulness = ui->playfulnessSpin->value();
    patience = ui->patienceSpin->value();
    independence = ui->independenceSpin->value();
    obedience = ui->obedienceSpin->value();

    if(DOBValidator.validate(DOB,pos)!=Acceptable &&DOB!=""){
        ui->emptyAnimalLbl->setHidden(false);
    }else if(breedValidator.validate(breed,pos)!=Acceptable){
        ui->emptyAnimalLbl->setHidden(false);
    }else if(name == ""||breed == ""||(ageYears == 0 && ageMonths == 0)||gender==""||species==""){
        ui->emptyAnimalLbl->setHidden(false);
    }else{

        ui->temperamentSpin->setValue(1);
        ui->trainabilitySpin->setValue(1);
        ui->intelligenceSpin->setValue(1);
        ui->mischievousnessSpin->setValue(1);
        ui->animalFriendlySpin->setValue(1);
        ui->friendlyStrangerSpin->setValue(1);
        ui->energySpin->setValue(1);
        ui->childFriendlySpin->setValue(1);
        ui->playfulnessSpin->setValue(1);
        ui->patienceSpin->setValue(1);
        ui->independenceSpin->setValue(1);
        ui->obedienceSpin->setValue(1);

        displayNewAnimal(manageAnimals.addAnimal(breed,ageYears,ageMonths,gender, vaccinated, name,species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfulness, patience, independence, obedience, DOB),animalNum);
        ui->nameTxt->clear();
        ui->breedTxt->clear();
        ui->speciesCombo->setCurrentIndex(-1);
        ui->genderCombo->setCurrentIndex(-1);
        ui->vaccinatedChk->setChecked(false);
        ui->yearsSpn->setValue(0);
        ui->monthsSpn->setValue(0);
        ui->emptyAnimalLbl->setHidden(true);
    }
}

/**
Function: on_addClientBtn_clicked()
in:
out:
return:
purpose: Handle adding a new Client to the database and updating the display as a new Client is added.
**/
//change this function to pass info to client management, return bool
void CUACSView::on_addClientBtn_clicked()
{
    QString first, last, postal, pass, town, prov, mail, addLn1, addLn2, phone, user, confirmPass;
    bool allFull = true;
    int pos = 0;
    user = ui->usernameTxt->text();
    QRegExp textNoSpaces("^[a-zA-Z]*$");
    QRegExpValidator validateTextOnly(textNoSpaces);
    first = ui->firstNameTxt->text();
    last = ui->lastNameTxt->text();
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
    if(!manageClients.checkUsername(user)){//checkuser will check regex, if the name is available, and ensure the name has enough characters
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(validateTextOnly.validate(first,pos)!=Acceptable||first==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
    if(validateTextOnly.validate(last,pos)!=Acceptable||last==""){
        ui->emptyClientLbl->setHidden(false);
        allFull = false;
    }
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
    } else if(ui->notFriendlyStrange->isChecked()){
        strangeFriend = 3;
    }


    if(allFull){
        //clients.push_back(manageClients.addClient(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2));
        displayNewClient(manageClients.addClient(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2, ownCon, ownRank, socab, socRank,behav, behavRank,strangeFriend, childFriend), clientNum);
        ui->passConLbl->setHidden(true);
        ui->usernameTxt->clear();
        ui->firstNameTxt->clear();
        ui->lastNameTxt->clear();
        ui->addressLine1Txt->clear();
        ui->addressLine2Txt->clear();
        ui->passwordTxt->clear();
        ui->confirmPasswordTxt->clear();
        ui->cityTxt->clear();
        ui->phoneTxt->clear();
        ui->postalCodeTxt->clear();
        ui->provinceCombo->setCurrentIndex(-1);
        ui->emailTxt->clear();
        ui->emptyClientLbl->setHidden(true);

    }
}

/**
Function: on_detailedClientsBtn_clicked()
in:
out:
return:
purpose: Calls and displays the detailedClientView when detailedClient button is clicked
**/
void CUACSView::on_detailedClientsBtn_clicked()
{
    detailedView->setClients(manageClients.getClients());
    detailedView->show();
}

void CUACSView::setSelectedClient(int row, int _x, int _y, int _z){
    detailedView->setIndex(row);
}

void CUACSView::setSelectedAnimal(int row, int _x, int _y, int _z){
    animalView->setIndex(row);
}
/**
Function: on_pushButton_clicked()
in:
out:
return:
purpose: Calls and displays the animalDetailedView when the button is clicked
**/
void CUACSView::on_pushButton_clicked()
{
    animalView->setAnimals(manageAnimals.getAnimals());
    animalView->show();
}

/**
Function: on_runACMbutton_clicked()
in:
out:
return:
purpose: Calls the ACM algorithm and populates the ACM view with the results.
**/
void CUACSView::on_runACMbutton_clicked(){
    vector<std::pair<Client, Animal>> animalClientPairs = ACM::runACM(manageAnimals.getAnimals(), manageClients.getClients());
    displayACMResults(animalClientPairs);
}
