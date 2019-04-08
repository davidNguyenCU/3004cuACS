#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include <QString>
#include <vector>
#include "client.h"
#include "databasemanager.h"
#include <QRegExpValidator>
#include <QRegExp>

class ClientManager
{
public:
    ClientManager(databaseManager *data);
    ClientManager();
    vector<Client> getClients();
    bool checkUsername(QString newUser, QString &errorString);
    Client* login(QString, QString);
    Client addClient(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank, int strangeFriend, int childFriend);
private:
    vector<Client> clients;
    databaseManager *db;
};

#endif // CLIENTMANAGER_H
