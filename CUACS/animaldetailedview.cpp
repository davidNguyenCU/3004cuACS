#include "animaldetailedview.h"
#include "ui_animaldetailedview.h"

AnimalDetailedView::AnimalDetailedView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailedView)
{
    ui->setupUi(this);
    index = 0;
    edit(false);
}

AnimalDetailedView::~AnimalDetailedView()
{
    delete ui;
}

/**
Function: setAnimals
in: A vector of Animals that will be displayed in detail
out:
return:
purpose: Initialize the animals in the detailed View and display the first animal
**/
void AnimalDetailedView::setAnimals(vector<Animal> a){
    animals = a;
    if(animals.size()!=0){
        //ui->ageLbl->setText(QString::number(animals[0].getYears()) + "/" + QString::number(animals[0].getMonths()));
        ui->yearSpin->setValue(animals[0].getYears());
        ui->monthSpin->setValue(animals[0].getMonths());
        ui->nameLbl->setText(animals[0].getName());
        ui->breedLbl->setText(animals[0].getBreed());
        ui->speciesLbl->setText(animals[0].getSpecies());
        ui->DOBLbl->setText(animals[0].getDOB());
        ui->genderLbl->setText(animals[0].getGender());
        ui->checkBox->setChecked(animals[0].isVaccinated());

        //This sets the algorithm attributes
        ui->animalSpin->setValue(animals[0].getSocialAttitutde());
        ui->energySpin->setValue(animals[0].getEnergy());
        ui->independenceSpin->setValue(animals[0].getIndependence());
        ui->intSpin->setValue(animals[0].getIntelligence());
        ui->miscSpin->setValue(animals[0].getMischievousness());
        ui->obedienceSpin->setValue(animals[0].getObedience());
        ui->patienceSpin->setValue(animals[0].getPatience());
        ui->playSpin->setValue(animals[0].getPlayfulness());
        ui->strangerSpin->setValue(animals[0].getStrangerFriendly());
        ui->childFriendlySpin->setValue(animals[0].getChildFriendly());
        ui->tempSpin->setValue(animals[0].getTemperament());
        ui->trainSpin->setValue(animals[0].getTrainability());

    }
}

/**
Function: on_previousBtn_clicked()
in:
out:
return:
purpose: Displays the previous Animal or loops back around to the last animal upon clicking the previous button
**/
void AnimalDetailedView::on_previousBtn_clicked()
{
    if(index == 0){
        index = animals.size()-1;
    }else{
        index-=1;
    }
    ui->yearSpin->setValue(animals[index].getYears());
    ui->monthSpin->setValue(animals[index].getMonths());
    ui->nameLbl->setText(animals[index].getName());
    ui->breedLbl->setText(animals[index].getBreed());
    ui->speciesLbl->setText(animals[index].getSpecies());
    ui->DOBLbl->setText(animals[index].getDOB());
    ui->genderLbl->setText(animals[index].getGender());
    ui->checkBox->setChecked(animals[index].isVaccinated());

    //This sets the algorithm attributes
    ui->animalSpin->setValue(animals[index].getSocialAttitutde());
    ui->energySpin->setValue(animals[index].getEnergy());
    ui->independenceSpin->setValue(animals[index].getIndependence());
    ui->intSpin->setValue(animals[index].getIntelligence());
    ui->miscSpin->setValue(animals[index].getMischievousness());
    ui->obedienceSpin->setValue(animals[index].getObedience());
    ui->patienceSpin->setValue(animals[index].getPatience());
    ui->playSpin->setValue(animals[index].getPlayfulness());
    ui->strangerSpin->setValue(animals[index].getStrangerFriendly());
    ui->childFriendlySpin->setValue(animals[index].getChildFriendly());
    ui->tempSpin->setValue(animals[index].getTemperament());
    ui->trainSpin->setValue(animals[index].getTrainability());
    edit(false);
}

void AnimalDetailedView::edit(bool enabled){
    ui->yearSpin->setEnabled(enabled);
    ui->monthSpin->setEnabled(enabled);
    ui->checkBox->setEnabled(enabled);
    ui->animalSpin->setEnabled(enabled);
    ui->energySpin->setEnabled(enabled);
    ui->independenceSpin->setEnabled(enabled);
    ui->intSpin->setEnabled(enabled);
    ui->miscSpin->setEnabled(enabled);
    ui->obedienceSpin->setEnabled(enabled);
    ui->patienceSpin->setEnabled(enabled);
    ui->playSpin->setEnabled(enabled);
    ui->strangerSpin->setEnabled(enabled);
    ui->childFriendlySpin->setEnabled(enabled);
    ui->tempSpin->setEnabled(enabled);
    ui->trainSpin->setEnabled(enabled);
}

/**
Function: on_nextBtn_clicked()
in:
out:
return:
purpose:Display the next animal or loops back to the beginning when the next button is clicked
**/
void AnimalDetailedView::on_nextBtn_clicked()
{
    if(index == (animals.size()-1)){
        index = 0;
    }else{
        index+=1;
    }
    ui->yearSpin->setValue(animals[index].getYears());
    ui->monthSpin->setValue(animals[index].getMonths());
    ui->nameLbl->setText(animals[index].getName());
    ui->breedLbl->setText(animals[index].getBreed());
    ui->speciesLbl->setText(animals[index].getSpecies());
    ui->DOBLbl->setText(animals[index].getDOB());
    ui->genderLbl->setText(animals[index].getGender());
    ui->checkBox->setChecked(animals[index].isVaccinated());

    //This sets the algorithm attributes
    ui->animalSpin->setValue(animals[index].getSocialAttitutde());
    ui->energySpin->setValue(animals[index].getEnergy());
    ui->independenceSpin->setValue(animals[index].getIndependence());
    ui->intSpin->setValue(animals[index].getIntelligence());
    ui->miscSpin->setValue(animals[index].getMischievousness());
    ui->obedienceSpin->setValue(animals[index].getObedience());
    ui->patienceSpin->setValue(animals[index].getPatience());
    ui->playSpin->setValue(animals[index].getPlayfulness());
    ui->strangerSpin->setValue(animals[index].getStrangerFriendly());
    ui->childFriendlySpin->setValue(animals[index].getChildFriendly());
    ui->tempSpin->setValue(animals[index].getTemperament());
    ui->trainSpin->setValue(animals[index].getTrainability());
    edit(false);
}
