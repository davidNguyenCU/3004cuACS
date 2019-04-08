#include "clientmanager.h"

ClientManager::ClientManager(databaseManager *data)
{
    db = data;
    clients = db->getClients();
}
ClientManager::ClientManager(){}

/**
Function: addClient()
in: QString newUser
out: QString errorString, to track the errors caused when validating the username
return: Bool stating whether or not the username is acceptable
purpose: Validate whether the given username is already taken, as well as whether or not it meets the criteria
**/
bool ClientManager::checkUsername(QString newUser, QString& errorString){
    int pos = 0;

    //update error string if username is empty
    if(newUser==""){
        errorString += "Please enter a username.\n";
        return false;
    }

    //Check whether the username is taken
    for(int i = 0;i<clients.size();i++){
        if(newUser.toUpper()==clients[i].getUsername().toUpper()){
            errorString += "That username is already selected.\n";
            return false;
        }
    }

    //validate whether the username meets the given criteria
    QRegExp userRegex("^[a-zA-Z0-9]*$");
    QRegExpValidator userValid(userRegex);
    if(userValid.validate(newUser,pos)!=QValidator::Acceptable){
        errorString += "Please ensure that your username only contains letters and numbers.\n";
        return false;
    }
    return true;
}

/**
Function: addClient()
in: QString user, QString pass
out:
return: Client with the corresponding login information
purpose: verify whether there is a user with the given username and password
**/
Client* ClientManager::login(QString user, QString pass){
    for (int i = 0; i<clients.size();i++){

        if(clients[i].getUsername().toUpper() == user.toUpper()){
            if(clients[i].getPassword() == pass){
                return &(clients[i]);
            }else{
                errorInformation *e = new errorInformation("Incorrect Password.");
                e->show();
                return NULL;
            }
        }
    }
    errorInformation *e = new errorInformation("No user with that username exists.");
    e->show();
    return NULL;
}

//get the clients vector
vector<Client> ClientManager::getClients(){return clients;}

/**
Function: addClient()
in: QString first,QString last, QString postal, QString town, QString prov, QString user,QString mail, QString pass, QString phone, QString addLn1, QString addLn2, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank,int strangeFriend, int childFriend
out:
return: Client created using the given values
purpose: Create a new client from the given values, and add it to the database
**/
Client ClientManager::addClient(QString first,QString last, QString postal, QString town, QString prov, QString user,QString mail, QString pass, QString phone, QString addLn1, QString addLn2, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank,int strangeFriend, int childFriend){
    Client newClient = Client(first,last,postal,town,prov,user,mail,pass,phone,addLn1,addLn2, ownCon, ownRank, socab, socRank, behave,behavRank, strangeFriend, childFriend);
    clients.push_back(newClient);
    db->addClient(newClient);
    return newClient;
}
