#include "animal.h"




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

/**
Function: getTemperament()
in:
out:
return: The temperance ranking of the Animal as an int
purpose: Gets the temperance score of the Animal
**/
int Animal::getTemperament() const
{
    return temperament;
}

/**
Function: getTrainability()
in:
out:
return: The trainability ranking of the Animal as an int
purpose: Gets the score of how trained the Animal is
**/
int Animal::getTrainability() const
{
    return trainability;
}

/**
Function: getIntelligence()
in:
out:
return: The intelligence ranking of the Animal as an int
purpose: Gets the score of how smart the Animal is
**/
int Animal::getIntelligence() const
{
    return intelligence;
}

/**
Function: getMischievousness()
in:
out:
return: The mischievousness ranking of the Animal as an int
purpose: Gets the score of how mischievous the Animal is
**/
int Animal::getMischievousness() const
{
    return mischievousness;
}

/**
Function: getSocialAttitude()
in:
out:
return: The social attitude ranking of the Animal as an int
purpose: Gets the score of how mischievous the Animal is
**/
int Animal::getSocialAttitutde() const
{
    return socialAttitude;
}

/**
Function: getStrangerFriendly()
in:
out:
return: The stranger friendly ranking of the Animal as an int
purpose: Gets the score of how friendly the Animal is to strangers
**/
int Animal::getStrangerFriendly() const
{
    return strangerFriendly;
}

/**
Function: getEnergy()
in:
out:
return: The energy ranking of the Animal as an int
purpose: Gets the score of how energetic the Animal has
**/
int Animal::getEnergy() const
{
    return energy;
}

/**
Function: getChildFriendly()
in:
out:
return: The child friendly ranking of the Animal as an int
purpose: Gets the score of how friendly the Animal is with children
**/
int Animal::getChildFriendly() const
{
    return childFriendly;
}

/**
Function: getPlayfulness()
in:
out:
return: The playfulness ranking of the Animal as an int
purpose: Gets the score of how playful the Animal is
**/
int Animal::getPlayfulness() const
{
    return playfulness;
}

/**
Function: getPatience()
in:
out:
return: The patience ranking of the Animal as an int
purpose: Gets the score of how patient the Animal is
**/
int Animal::getPatience() const
{
    return patience;
}

/**
Function: getIndependence()
in:
out:
return: The independence ranking of the Animal as an int
purpose: Gets the score of how independent the Animal is
**/
int Animal::getIndependence() const
{
    return independence;
}

/**
Function: getObedience()
in:
out:
return: The obedience ranking of the Animal as an int
purpose: Gets the score of how obedient the Animal is
**/
int Animal::getObedience() const
{
    return obedience;
}
