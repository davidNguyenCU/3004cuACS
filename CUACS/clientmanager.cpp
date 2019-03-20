#include "clientmanager.h"

ClientManager::ClientManager(databaseManager *data)
{
    db = data;
    clients = db->getClients();
}
ClientManager::ClientManager(){}
bool ClientManager::checkUsername(QString newUser){
    int pos = 0;
    if(newUser==""){
        return false;
    }
    for(int i = 0;i<clients.size();i++){
        if(newUser==clients[i].getUsername()){
            return false;
        }
    }
    QRegExp userRegex("^[a-zA-Z0-9]*$");
    QRegExpValidator userValid(userRegex);
    if(userValid.validate(newUser,pos)!=QValidator::Acceptable){
        return false;
    }
    return true;
}

Client* ClientManager::login(QString user, QString pass){
    for (int i = 0; i<clients.size();i++){
        if(clients[i].getPassword()==pass && clients[i].getUsername()==user){
            return &(clients[i]);
        }
    }
    return NULL;
}

vector<Client> ClientManager::getClients(){return clients;}
Client ClientManager::addClient(QString first,QString last, QString postal, QString town, QString prov, QString user,QString mail, QString pass, QString phone, QString addLn1, QString addLn2, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank,int strangeFriend, int childFriend){
    Client newClient = Client(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2, ownCon, ownRank, socab, socRank, behave,behavRank, strangeFriend, childFriend);
    clients.push_back(newClient);
    db->addClient(newClient);
    return newClient;
}
