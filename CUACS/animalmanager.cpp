#include "animalmanager.h"

AnimalManager::AnimalManager()
{}
AnimalManager::AnimalManager(databaseManager *data){
    db = data;
    animals = db->getAnimals();
}
AnimalManager::~AnimalManager(){
    delete db;
}

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

vector<Animal> AnimalManager::getAnimals(){return animals;}

Animal AnimalManager::addAnimal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB){
    if(DOB==""){
        animals.push_back(Animal(animals.size()+1, aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed));
    }else{
        animals.push_back(Animal(animals.size()+1, aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed, DOB));
    }
    db->addAnimal(animals[animals.size()-1]);
    return animals[animals.size()-1];
}
