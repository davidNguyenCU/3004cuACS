#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QDebug>
#include <qsqlerror.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "animal.h"
#include "client.h"
#include <vector>
#include <iostream>

class databaseManager
{
public:
    databaseManager(const QString& path);
    bool createTable();
    void populateTables();
    void addAnimal(Animal);
    void addClient(Client);
    vector<Animal> getAnimals();
    vector<Client> getClients();
private:
    QSqlDatabase localDB;
};

#endif // DATABASEMANAGER_H
