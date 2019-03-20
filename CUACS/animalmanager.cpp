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
vector<Animal> AnimalManager::getAnimals(){return animals;}

Animal AnimalManager::addAnimal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB){
    if(DOB==""){
        animals.push_back(Animal(aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed));
    }else{
        animals.push_back(Animal(aBreed,ageY,ageM,aGender, isVaccinated, aName,aSpecies, temp, train, intel, misc, soc, strange, nrg, child, play, pat, indp, obed, DOB));
    }
    db->addAnimal(animals[animals.size()-1]);
    return animals[animals.size()-1];
}
