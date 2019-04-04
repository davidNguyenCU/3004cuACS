#ifndef ANIMALMANAGER_H
#define ANIMALMANAGER_H
#include <QString>
#include <vector>
#include "animal.h"
#include "databasemanager.h"
#include <QRegExpValidator>
#include <QRegExp>


class AnimalManager
{
public:
    AnimalManager(databaseManager *data);
    AnimalManager();
    ~AnimalManager();
    vector<Animal> getAnimals();
    Animal addAnimal(QString aBreed,int ageY,int ageM,QString aGender,bool isVaccinated,QString aName,QString aSpecies,int temp, int train, int intel, int misc, int soc, int strange, int nrg, int child, int play, int pat, int indp, int obed, QString DOB);
    void editAnimal(bool, int,int,int,int,int,int,int,int,int,int,int,int, int, int, int);
private:
    vector<Animal> animals;
    databaseManager *db;
};

#endif // ANIMALMANAGER_H
