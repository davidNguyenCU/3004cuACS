#include "animaldetailedview.h"
#include "ui_animaldetailedview.h"

AnimalDetailedView::AnimalDetailedView(AnimalManager& animal, QTableWidget *t, bool staff,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailedView)
{
    ui->setupUi(this);
    index = 0;
    edit(false);
    am = animal;
    table = t;
    ui->editBtn->setVisible(staff);
    editing = false;
}

AnimalDetailedView::~AnimalDetailedView()
{
    delete ui;
}

//Set the current index for the animal to view
void AnimalDetailedView::setIndex(int row){index = row;}


/**
Function: update()
out:
return:
purpose: Update the detailed animal display with the information of the animal at the given index
**/
void AnimalDetailedView::update(){
    if(animals.size()!=0){
        //ui->ageLbl->setText(QString::number(animals[0].getYears()) + "/" + QString::number(animals[0].getMonths()));
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
    }
}
/**
Function: setAnimals
in: A vector of Animals that will be displayed in detail
out:
return:
purpose: Initialize the animals in the detailed View and display the first animal
**/
void AnimalDetailedView::setAnimals(vector<Animal> anim){
    animals = anim;
    update();
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
    update();
    edit(false);
    ui->editBtn->setText("Edit");
    editing = false;
}

/**
Function: edit()
in: bool enabled
out:
return:
purpose: Enable the different inputs on the display to be changed
**/
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
    vector<Animal> animals = am.getAnimals();
    if(index == (animals.size()-1)){
        index = 0;
    }else{
        index+=1;
    }
    update();
    edit(false);
    ui->editBtn->setText("Edit");
    editing = false;
}

/**
Function: on_editBtn_clicked()
in:
out:
return:
purpose: If the user is in edit mode, save the current values, otherwise turn on edit mode
**/
void AnimalDetailedView::on_editBtn_clicked()
{
    if (!editing){
        ui->editBtn->setText("Save");
        edit(true);
        editing = true;
    }else{
        ui->editBtn->setText("Edit");
        edit(false);
        editing = false;

        //get the information that the user has input
        int year, month, soc,energy, indep, intel, misc, pat, play, obed, strange, child, temp, train;
        bool vacc = ui->checkBox->isChecked();
        year = ui->yearSpin->value();
        month = ui->monthSpin->value();
        soc = ui->animalSpin->value();
        energy = ui->energySpin->value();
        indep = ui->independenceSpin->value();
        intel = ui->intSpin->value();
        misc = ui->miscSpin->value();
        pat = ui->patienceSpin->value();
        play = ui->playSpin->value();
        obed = ui->obedienceSpin->value();
        strange = ui->strangerSpin->value();
        child = ui->childFriendlySpin->value();
        temp = ui->tempSpin->value();
        train = ui->trainSpin->value();

        am.editAnimal(vacc,year,month,soc,energy,indep,intel,misc,obed,pat,play,strange,child,temp,train,index);
        int row = index;

        //update the table view
        table->setCellWidget(row,5,new QLabel(QString::number(am.getAnimals()[index].getYears()) + "/" + QString::number(am.getAnimals()[index].getMonths())));
        QLabel *vaccinated;
        if(am.getAnimals()[index].isVaccinated()){
            vaccinated = new QLabel("Yes");
        }else{
            vaccinated = new QLabel("No");
        }
        table->setCellWidget(row,6,vaccinated);

    }
}
