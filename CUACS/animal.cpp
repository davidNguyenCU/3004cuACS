#include "animal.h"

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

QString Animal::getBreed() const{
    return breed;
}
QString Animal::getDOB() const{
    return dateOfBirth;
}
QString Animal::getGender() const{
    return gender;
}
QString Animal::getSpecies() const{
    return species;
}
QString Animal::getName() const{
    return name;
}
int Animal::getYears() const{
    return ageYears;
}
int Animal::getMonths() const{
    return ageMonths;
}
bool Animal::isVaccinated() const{
    return vaccinated;
}
