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

//set the animals and displays the first animal
void AnimalDetailedView::setAnimals(vector<Animal> &a){
    animals = a;
    if(animals.size()!=0){
        ui->ageLbl->setText(animals[0].getYears() + "/" + animals[0].getMonths());
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
void AnimalDetailedView::on_previousBtn_clicked()
{
    if(index == 0){
        index = animals.size()-1;
    }else{
        index-=1;
    }
    ui->ageLbl->setText(animals[index].getYears() + "/" + animals[index].getMonths());
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

void AnimalDetailedView::on_nextBtn_clicked()
{
    if(index == (animals.size()-1)){
        index = 0;
    }else{
        index+=1;
    }
            ui->ageLbl->setText(animals[index].getYears() + "/" + animals[index].getMonths());
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
