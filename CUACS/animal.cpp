#include "animal.h"

//Constructor for Animal class
Animal::Animal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies, QString DOB)
{
    breed = aBreed;
    ageYears = ageY;
    ageMonths = ageM;
    gender = aGender;
    vaccinated = isVaccinated;
    name = aName;
    dateOfBirth = DOB;
    species = aSpecies;
}


Animal::Animal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB){
    breed = aBreed;
    ageYears = ageY;
    ageMonths = ageM;
    gender = aGender;
    vaccinated = isVaccinated;
    name = aName;
    dateOfBirth = DOB;
    species = aSpecies;
    temperament = temp;
    trainability = train;
    intelligence = intel;
    mischievousness = misc;
    socialAttitude = soc;
    strangerFriendly = strange;
    energy = nrg;
    childFriendly = child;
    playfulness = play;
    patience = pat;
    independence = indp;
    obedience = obed;
}

Animal::~Animal(){
}

/**
Function: getBreed()
in:
out:
return: Breed of the current Animal as a QString
purpose: Get the breed of the current Animal
**/
QString Animal::getBreed() const{
    return breed;
}

/**
Function:getDOB()
in:
out:
return: Date of birth of the current Animal as a QString
purpose: Get the DOB of the current Animal
**/
QString Animal::getDOB() const{
    return dateOfBirth;
}

/**
Function: getGender()
in:
out:
return: Gender of the current Animal as a QString
purpose: Get the gender of the current Animal
**/
QString Animal::getGender() const{
    return gender;
}

/**
Function: getSpecies()
in:
out:
return: Species of the current Animal as a QString
purpose: Get the species of the current Animal
**/
QString Animal::getSpecies() const{
    return species;
}

/**
Function: getName()
in:
out:
return: Name of the current Animal as a QString
purpose: Get the name of the current Animal
**/
QString Animal::getName() const{
    return name;
}

/**
Function: getYears()
in:
out:
return: The Age in years of the current Animal as an int
purpose: Get how many years old the current Animal is
**/
int Animal::getYears() const{
    return ageYears;
}

/**
Function: getMonths()
in:
out:
return: The Age in months of the current Animal as an int
purpose: Get how many months old the Animal is since its last birthday
**/
int Animal::getMonths() const{
    return ageMonths;
}

/**
Function: isVaccinated()
in:
out:
return: Whether or not the Animal is vaccinated as a bool
purpose: Get whether or not the current Animal is vaccinated
**/
bool Animal::isVaccinated() const{
    return vaccinated;
}

int Animal::getTemperament() const
{
    return temperament;
}

int Animal::getTrainability() const
{
    return trainability;
}

int Animal::getIntelligence() const
{
    return intelligence;
}

int Animal::getMischievousness() const
{
    return mischievousness;
}

int Animal::getSocialAttitutde() const
{
    return socialAttitude;
}

int Animal::getStrangerFriendly() const
{
    return strangerFriendly;
}

int Animal::getEnergy() const
{
    return energy;
}

int Animal::getChildFriendly() const
{
    return childFriendly;
}

int Animal::getPlayfulness() const
{
    return playfulness;
}

int Animal::getPatience() const
{
    return patience;
}

int Animal::getIndependence() const
{
    return independence;
}

int Animal::getObedience() const
{
    return obedience;
}
