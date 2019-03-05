#include "animaldetailedview.h"
#include "ui_animaldetailedview.h"

AnimalDetailedView::AnimalDetailedView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailedView)
{
    ui->setupUi(this);
    index = 0;
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
void AnimalDetailedView::setAnimals(vector<Animal> &a){
    animals = a;
    if(animals.size()!=0){
        ui->ageLbl->setText(QString::number(animals[0].getYears()) + "/" + QString::number(animals[0].getMonths()));
        ui->nameLbl->setText(animals[0].getName());
        ui->breedLbl->setText(animals[0].getBreed());
        ui->speciesLbl->setText(animals[0].getSpecies());
        ui->DOBLbl->setText(animals[0].getDOB());
        ui->genderLbl->setText(animals[0].getGender());
        if(animals[0].isVaccinated()){
            ui->vaccinatedLbl->setText("Yes");
        }else{
            ui->vaccinatedLbl->setText("No");
        }

        //This sets the algorithm attributes
        ui->animalsAttitudeLbl->setText(QString::number(animals[0].getSocialAttitutde()));
        ui->energyLbl->setText(QString::number(animals[0].getEnergy()));
        ui->independenceLbl->setText(QString::number(animals[0].getIndependence()));
        ui->intelligenceLbl->setText(QString::number(animals[0].getIntelligence()));
        ui->mischievousnessLbl->setText(QString::number(animals[0].getMischievousness()));
        ui->obedienceLbl->setText(QString::number(animals[0].getObedience()));
        ui->patienceLbl->setText(QString::number(animals[0].getPatience()));
        ui->playfulnessLbl->setText(QString::number(animals[0].getPlayfulness()));
        ui->strangersAttitudeLbl->setText(QString::number(animals[0].getStrangerFriendly()));
        ui->childFriendlyLbl->setText(QString::number(animals[0].getChildFriendly()));
        ui->temperamentLbl->setText(QString::number(animals[0].getTemperament()));
        ui->trainabilityLbl->setText(QString::number(animals[0].getTrainability()));

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
    ui->ageLbl->setText(QString::number(animals[index].getYears()) + "/" + QString::number(animals[index].getMonths()));
            ui->nameLbl->setText(animals[index].getName());
            ui->breedLbl->setText(animals[index].getBreed());
            ui->speciesLbl->setText(animals[index].getSpecies());
            ui->DOBLbl->setText(animals[index].getDOB());
            ui->genderLbl->setText(animals[index].getGender());
            if(animals[index].isVaccinated()){
                ui->vaccinatedLbl->setText("Yes");
            }else{
                ui->vaccinatedLbl->setText("No");
            }

            //This sets the algorithm attributes
            ui->animalsAttitudeLbl->setText(QString::number(animals[index].getSocialAttitutde()));
            ui->energyLbl->setText(QString::number(animals[index].getEnergy()));
            ui->independenceLbl->setText(QString::number(animals[index].getIndependence()));
            ui->intelligenceLbl->setText(QString::number(animals[index].getIntelligence()));
            ui->mischievousnessLbl->setText(QString::number(animals[index].getMischievousness()));
            ui->obedienceLbl->setText(QString::number(animals[index].getObedience()));
            ui->patienceLbl->setText(QString::number(animals[index].getPatience()));
            ui->playfulnessLbl->setText(QString::number(animals[index].getPlayfulness()));
            ui->strangersAttitudeLbl->setText(QString::number(animals[index].getStrangerFriendly()));
            ui->childFriendlyLbl->setText(QString::number(animals[index].getChildFriendly()));
            ui->temperamentLbl->setText(QString::number(animals[index].getTemperament()));
            ui->trainabilityLbl->setText(QString::number(animals[index].getTrainability()));
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
            ui->ageLbl->setText(QString::number(animals[index].getYears()) + "/" + QString::number(animals[index].getMonths()));
            ui->nameLbl->setText(animals[index].getName());
            ui->breedLbl->setText(animals[index].getBreed());
            ui->speciesLbl->setText(animals[index].getSpecies());
            ui->DOBLbl->setText(animals[index].getDOB());
            ui->genderLbl->setText(animals[index].getGender());
            if(animals[index].isVaccinated()){
                ui->vaccinatedLbl->setText("Yes");
            }else{
                ui->vaccinatedLbl->setText("No");
            }

            //This sets the algorithm attributes
            ui->animalsAttitudeLbl->setText(QString::number(animals[index].getSocialAttitutde()));
            ui->energyLbl->setText(QString::number(animals[index].getEnergy()));
            ui->independenceLbl->setText(QString::number(animals[index].getIndependence()));
            ui->intelligenceLbl->setText(QString::number(animals[index].getIntelligence()));
            ui->mischievousnessLbl->setText(QString::number(animals[index].getMischievousness()));
            ui->obedienceLbl->setText(QString::number(animals[index].getObedience()));
            ui->patienceLbl->setText(QString::number(animals[index].getPatience()));
            ui->playfulnessLbl->setText(QString::number(animals[index].getPlayfulness()));
            ui->strangersAttitudeLbl->setText(QString::number(animals[index].getStrangerFriendly()));
            ui->childFriendlyLbl->setText(QString::number(animals[index].getChildFriendly()));
            ui->temperamentLbl->setText(QString::number(animals[index].getTemperament()));
            ui->trainabilityLbl->setText(QString::number(animals[index].getTrainability()));
}
