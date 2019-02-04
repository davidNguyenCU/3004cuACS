#include "cuacsview.h"
#include "ui_cuacsview.h"

CUACSView::CUACSView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUACSView)
{
    ui->setupUi(this);

    ui->genderCombo->insertItem(0, "Male");
    ui->genderCombo->insertItem(1,"Female");
    QString species[] = {"Select Animal...","Dog","Cat","Bird","Turtle","Frog","Hamster","Guinea Pig"};
    for(int i = 0;i<7; i++){
        ui->speciesCombo->insertItem(i,species[i]);
    }

    ui->emptyItemlbl->setHidden(true);
}

CUACSView::~CUACSView()
{
    delete ui;
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

    if(name == ""||breed == ""||species == "Select Animal..."||(ageYears == 0 && ageMonths == 0)){
        ui->emptyItemlbl->setHidden(false);
    }else{
        if(DOB==""){
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species));
            ui->DOBTxt->clear();
        }else{
            animals.push_back(Animal(breed,ageYears,ageMonths,gender, vaccinated, name,species, DOB));
        }
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
