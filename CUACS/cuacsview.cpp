#include "cuacsview.h"
#include "ui_cuacsview.h"

CUACSView::CUACSView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUACSView)
{
    ui->setupUi(this);

    animalDB.createTable();
    animals = animalDB.getAnimals();

    ui->genderCombo->insertItem(0, "Male");
    ui->genderCombo->insertItem(1,"Female");
    QString species[] = {"Dog","Cat","Bird","Turtle","Frog","Hamster","Guinea Pig"};
    for(int i = 0;i<7; i++){
        ui->speciesCombo->insertItem(i,species[i]);
    }
    ui->speciesCombo->setCurrentIndex(-1);
    ui->genderCombo->setCurrentIndex(-1);
    ui->emptyItemlbl->setHidden(true);
    ui->animalTbl->setRowCount(animals.size());
    for(int i = 0;i< animals.size();i++){
        displayNewAnimal(animals[i]);
    }
}

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
    delete ui->emptyItemlbl;
    delete ui->addAnimalBtn;
    delete ui->tab_2;
    delete ui->animalTbl;
    delete ui->tab;
    delete ui->tabWidget;
    delete ui->centralWidget;
    delete ui->statusBar;
    delete ui;

}

void CUACSView::displayNewAnimal(Animal newAnimal){
    int row = animals.size();
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

void CUACSView::on_addAnimalBtn_clicked()
{
    QString name = ui->nameTxt->text();
    QString breed = ui->breedTxt->text();
    QString species = ui->speciesCombo->currentText();
    QString DOB = ui->DOBTxt->text();
    QString gender = ui->genderCombo->currentText();
    bool vaccinated = ui->vaccinatedChk->checkState();
    int ageYears = ui->yearsSpn->value();
    int ageMonths = ui->monthsSpn->value();

    if(name == ""||breed == ""||(ageYears == 0 && ageMonths == 0)||gender==""||species==""){
        ui->emptyItemlbl->setHidden(false);
    }else{
        if(DOB==""){
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species));

        }else{
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species, DOB));
            ui->DOBTxt->clear();
        }
        displayNewAnimal(animals[animals.size()-1]);
        animalDB.addAnimal(animals[animals.size()-1]);
        ui->nameTxt->clear();
        ui->breedTxt->clear();
        ui->speciesCombo->setCurrentIndex(-1);
        ui->genderCombo->setCurrentIndex(-1);
        ui->vaccinatedChk->setChecked(false);
        ui->yearsSpn->setValue(0);
        ui->monthsSpn->setValue(0);
        ui->emptyItemlbl->setHidden(true);
    }
}
