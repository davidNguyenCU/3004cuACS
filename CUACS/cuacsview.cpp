#include "cuacsview.h"
#include "ui_cuacsview.h"

//Constructor for the CUACSView, initializes all on screen items properly
CUACSView::CUACSView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUACSView)
{
    ui->setupUi(this);

    //My (Max) suggestions for the animal table is changing the name from animals to something else, and simply adding functions to the database manage for client, staff, etc.
    animalDB.createTable();
    animals = animalDB.getAnimals();

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

    ui->animalTbl->setRowCount(animals.size());
    for(unsigned int i = 0;i< animals.size();i++){
        displayNewAnimal(animals[i],i+1 );

    }
}

//destructor for CUACSView
CUACSView::~CUACSView()
{

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
    delete ui->tabWidget;
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
}

/**
Function: on_addAnimalBtn_clicked()
in:
out:
return:
purpose: Handle adding a new animal to the database and updating the display as a new animal is added.
**/
//This function will need to be updated in accordance with the new animal attributes
void CUACSView::on_addAnimalBtn_clicked()
{
    QString name = ui->nameTxt->text();
    QString breed = ui->breedTxt->text();
    QString species = ui->speciesCombo->currentText();
    QString DOB = ui->DOBTxt->text();
    QString gender = ui->genderCombo->currentText();

    QRegExp breedRegEx("^[a-z][a-z\\s]*$");
    QRegExpValidator breedValidator(breedRegEx);
    //format yyyy-mm-dd
    QRegExp DOBRegEx("\\d\\d\\d\\d-\\d\\d-\\d\\d");
    QRegExpValidator DOBValidator(DOBRegEx);
    bool vaccinated = ui->vaccinatedChk->checkState();
    int ageYears = ui->yearsSpn->value();
    int ageMonths = ui->monthsSpn->value();

    int pos = 0;
    if(DOBValidator.validate(DOB,pos)!=Acceptable &&DOB!=""){
        ui->emptyAnimalLbl->setHidden(false);
    }else if(breedValidator.validate(breed,pos)!=Acceptable){
        ui->emptyAnimalLbl->setHidden(false);
    }else if(name == ""||breed == ""||(ageYears == 0 && ageMonths == 0)||gender==""||species==""){
        ui->emptyAnimalLbl->setHidden(false);
    }else{
        if(DOB==""){
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species));

        }else{
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species, DOB));
            ui->DOBTxt->clear();
        }
        displayNewAnimal(animals[animals.size()-1], animals.size());
        animalDB.addAnimal(animals[animals.size()-1]);
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

void CUACSView::on_addClientBtn_clicked()
{
    QString first, last, postal, pass, town, prov, mail, addLn1, addLn2, phone, user, confirmPass;
    int pos = 0;
    //I will need to set up validators of some sort for username(ensure its unique), postal code, pass and confrimPass,
    //phone number, and maybe email
    user = ui->usernameTxt->text();
    QRegExp textNoSpaces("^[a-z]*$");
    QRegExpValidator validateTextOnly(textNoSpaces);
    first = ui->firstNameTxt->text();
    last = ui->lastNameTxt->text();
    QRegExp postalRegex("^([A-Za-z]\d[A-Za-z][-]?\d[A-Za-z]\d)");
    QRegExpValidator postalValidator(postalRegex);
    postal = ui->postalCodeTxt->text();

    QRegExp passRegex("^[a-zA-Z0-9]*$");
    QRegExpValidator validatePassword(passRegex);
    pass = ui->passwordTxt->text();
    confirmPass = ui->confirmPasswordTxt->text();
    town = ui->cityTxt->text();
    prov = ui->provinceCombo->currentText();
    mail = ui->emailTxt->text();
    QRegExp emailRegex("^\\w+@[a-zA-Z_]+?\\.[a-zA-Z]{2,3}$");
    QRegExpValidator emailValid(emailRegex);
    addLn1 = ui->addressLine1Txt->text();
    addLn2 = ui->addressLine2Txt->text();
    QRegExp phoneRegex("\\d-(\\d\\d\\d)-\\d\\d\\d-\\d\\d\\d\\d");
    QRegExpValidator phoneValidator(phoneRegex);
    phone = ui->phoneTxt->text();
    if(checkUsername(user)){//checkuser will check regex, if the name is available, and ensure the name has enough characters
        ui->emptyClientLbl->setHidden(false);
    }else if(validateTextOnly(first,pos)!=Acceptable||first==""){
        ui->emptyClientLbl->setHidden(false);
    }else if(validateTextOnly(last,pos)!=Acceptable||last=""){
        ui->emptyClientLbl->setHidden(false);
    }else if(postalValidator.validate(postal,pos)!=Acceptable||postal==""){
        ui->emptyClientLbl->setHidden(false);
    }else if(validatePassword.validate(pass,pos)!=Acceptable||pass!=""||pass!=confirmPass){
        ui->emptyClientLbl->setHidden(false);
    }else if(validateTextOnly(town,pos)!=Acceptable||town==""){
        ui->emptyClientLbl->setHidden(false);
    }else if(emailValid.validate(mail,pos) != Acceptable||mail==""){
        ui->emptyClientLbl->setHidden(false);
    }else if (prov ==""){
        ui->emptyClientLbl->setHidden(false);
    }else if(addLn1 == ""){
        ui->emptyClientLbl->setHidden(false);
    }else if(phoneValidator.validate(phone,pos)!=Acceptable||phone==""){
       ui->emptyClientLbl->setHidden(false);
    }else{
        if(addLn2==""){
            Client addClient = Client(first,last,postal,town,prov,user,mail,pass,phone,addLn1);
        }else{
            Client addClient = Client(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2);
        }

    }
}
