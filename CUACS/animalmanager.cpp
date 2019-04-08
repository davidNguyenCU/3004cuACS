#include "animalmanager.h"

AnimalManager::AnimalManager()
{}


AnimalManager::AnimalManager(databaseManager *data){
    db = data;
    animals = db->getAnimals();
}
AnimalManager::~AnimalManager(){
}

/**
Function: editAnimal
in:bool vacc, int year,int month,int soc,int energy,int indep,int intel,int misc,int obed,int pat,int play,int strange,int child, int temp, int train, int index
out:
return:
purpose: Takes in the values, and edits the animal that is stored at the given index
**/
void AnimalManager::editAnimal(bool vacc, int year,int month,int soc,int energy,int indep,int intel,int misc,int obed,int pat,int play,int strange,int child, int temp, int train, int index){
    animals[index].setVacc(vacc);
    animals[index].setYrs(year);
    animals[index].setMonths(month);
    animals[index].setSocialAttitude(soc);
    animals[index].setEnergy(energy);
    animals[index].setIndependence(indep);
    animals[index].setIntelligence(intel);
    animals[index].setMisc(misc);
    animals[index].setPatience(pat);
    animals[index].setPlay(play);
    animals[index].setObedience(obed);
    animals[index].setStrange(strange);
    animals[index].setChild(child);
    animals[index].setTemp(temp);
    animals[index].setTrain(train);
    animals[index].setID(animals[index].getID());
    db->updateAnimal(animals[index]);
}

//return animals vector
vector<Animal> AnimalManager::getAnimals(){return animals;}


/**
Function: addAnimal
in: QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB
out:
return: Animal created from the values
purpose: Takes in the values, and creates a new anima from those values, adding it to the database
**/
Animal AnimalManager::addAnimal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB){
    if(DOB==""){
        animals.push_back(Animal(aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed));
    }else{
        animals.push_back(Animal(aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed, DOB));
    }
    db->addAnimal(animals[animals.size()-1]);
    return animals[animals.size()-1];
}
