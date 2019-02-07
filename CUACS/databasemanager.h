#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "animal.h"
#include <vector>
#include <iostream>

class databaseManager
{
public:
    databaseManager(const QString& path);
    void addAnimal(Animal);
    vector<Animal> getAnimals();
private:
    QSqlDatabase animalDB;
};

#endif // DATABASEMANAGER_H
