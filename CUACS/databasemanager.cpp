#include "databasemanager.h"

//constructor for the databaseManager
databaseManager::databaseManager(const QString& path)
{
localDB = QSqlDatabase::addDatabase("QSQLITE");
localDB.setDatabaseName(path);


if (!localDB.open()){
    cout <<"Error: Failed connection with database";
}else{
    cout << "Successfully connected with database";
    }
}

/**
Function:
in:
out:
return: A bool indicating whether creating a table was successful
purpose: Checks whether or not the SQL table currently exists, and creates  it if it does not
**/
bool databaseManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    //Creates the animal's table
    query.prepare("CREATE TABLE IF NOT EXISTS animals("
                  "breed TEXT, "
                  "ageYears INTEGER, "
                  "ageMonths INTEGER, "
                  "gender TEXT, "
                  "vaccinated TEXT, "
                  "name TEXT, "
                  "DOB INTEGER, "
                  "species TEXT, "
                  "temperament INTEGER, "
                  "trainability INTEGER, "
                  "intelligence INTEGER, "
                  "mischievousness INTEGER, "
                  "socialAttitude INTEGER, "
                  "strangerFriendly INTEGER, "
                  "energy INTEGER, "
                  "childFriendly INTEGER, "
                  "playfullness INTEGER, "
                  "patience INTEGER, "
                  "independence INTEGER, "
                  "obedience INTEGER, "
                  "primary key (name));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'animals': one might already exist.";
        success = false;
    }

    //Creates the client's table
    query.prepare("CREATE TABLE IF NOT EXISTS clients("
                  "firstName TEXT, "
                  "lastName TEXT, "
                  "postalCode TEXT, "
                  "city TEXT, "
                  "province TEXT, "
                  "addressLine1 TEXT, "
                  "addressLine2 TEXT, "
                  "username TEXT, "
                  "passwrod TEXT, "
                  "email TEXT, "
                  "phoneNumber TEXT, "
                  "primary key (username));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'clients': one might already exist.";
        success = false;
    }

    return success;
}


void databaseManager::populateTables()
{
     QSqlQuery query;
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Australian Shepherd', 11, 8, 'Male', 'Yes','Buddy','UNKNOWN','Dog',5,5,5,5,5,5,5,5,5,5,5,5)");
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Maine Coon', 5, 6, 'Female', 'Yes','Delilah','UNKNOWN','Cat',6,6,5,5,5,2,5,5,3,5,5,5)");
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Maine Coon', 5, 6, 'Female', 'Yes','Delilah','UNKNOWN','Cat',6,6,5,5,5,2,5,5,3,5,5,5)");
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Yellow Box', 1, 1, 'Male', 'No','Leonard','2018-01-14','Turtle',4,6,5,3,5,2,5,5,3,5,7,5)");
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Canary', 0, 10, 'Female', 'Yes','Clementine','UNKNOWN','Bird',10,6,5,3,2,2,3,8,3,5,7,5)");
    query.exec("INSERT OR REPLACE INTO animals(breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES('Pug', 1, 8, 'Female', 'Yes','Cherry','2017-08-19','Dog',9,1,5,3,1,2,3,1,3,5,1,5)");
}


/**
Function: addAnimal(Animal)
in: Animal add to be inserted in to the database
out:
return: void
purpose: Adds a given animal to the SQL Database
**/
/*TO DO:
 * Add all the new algorithm attributes to the table
 * add the ID to the table as the primary key
 * Ensure that when an animal is created it is done using the full attribute constructor
 * Add a second table to be used for clients
 * Add an addClient function, which will take a client and add it to the table
 * Add a getClients function, which will return all clients in the database, in a vector
 */
void databaseManager::addAnimal(Animal add){
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO animals (breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience) "
                  "VALUES (:br, :ay, :am, :gen, :vacc, :name, :DOB, :spec, :temp, :train, :intel, :misc, :soci, :stra, :ener, :child, :play, :pati, :ind, :obe)");
    query.bindValue(":br",add.getBreed());
    query.bindValue(":ay",(add.getYears()));
    query.bindValue(":am",add.getMonths());
    query.bindValue(":gen",add.getGender());
    query.bindValue(":name",add.getName());
    query.bindValue(":DOB",add.getDOB());
    query.bindValue(":spec",add.getSpecies());
    if(add.isVaccinated()){
        query.bindValue(":vacc","Yes");
    }else{
        query.bindValue(":vacc","No");
    }

    query.bindValue(":temp", add.getTemperament());
    query.bindValue(":train", add.getTrainability());
    query.bindValue(":intel", add.getIntelligence());
    query.bindValue(":misc", add.getMischievousness());
    query.bindValue(":soci", add.getSocialAttitutde());
    query.bindValue(":stra", add.getStrangerFriendly());
    query.bindValue(":ener", add.getEnergy());
    query.bindValue(":child", add.getChildFriendly());
    query.bindValue(":play", add.getPlayfulness());
    query.bindValue(":pati", add.getPatience());
    query.bindValue(":ind", add.getIndependence());
    query.bindValue(":obe", add.getObedience());


    if(!query.exec()){
        qDebug()<<query.lastError()<<query.executedQuery();
    }
}

/**
Function: addClient(Client)
in: Client add to be inserted in to the database
out:
return: void
purpose: Adds a given Client to the SQL Database
**/
void databaseManager::addClient(Client add)
{
    QSqlQuery query;
    query.prepare("INSERT INTO OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber) "
                  "VALUES (:fName, :lName, :pCode, :cit, :pro, :ad1, :ad2, :user, :pass, :ema, :pNum)");
    query.bindValue(":fName",add.getfName());
    query.bindValue(":lName",add.getlName());
    query.bindValue(":pCode",add.getPostalCode());
    query.bindValue(":cit",add.getCity());
    query.bindValue(":pro",add.getProvince());
    query.bindValue(":ad1",add.getAddressLine1());
    query.bindValue(":ad2",add.getAddressLine2());
    query.bindValue(":user",add.getUsername());
    query.bindValue(":pass",add.getPassword());
    query.bindValue(":ema",add.getEmail());
    query.bindValue(":pNum",add.getPhoneNumber());

    if(!query.exec()){
        qDebug()<<query.lastError()<<query.executedQuery();
    }

}


/**
Function: getAnimals()
in:
out:
return: vector<Animal> containing all of the Animals in the database
purpose: return all animals currently in the database
**/
vector<Animal> databaseManager::getAnimals(){
    QSqlQuery query;
    vector<Animal> currentAnimals;
    query.exec("SELECT * FROM animals");

    while (query.next()){
        QString breed = query.value(0).toString();
        int ageYears = query.value(1).toInt();
        int ageMonths = query.value(2).toInt();
        QString gender = query.value(3).toString();
        QString vaccString = query.value(4).toString();
        QString name = query.value(5).toString();
        QString DOB = query.value(6).toString();
        QString species = query.value(7).toString();
        bool vaccBool;
        if(vaccString == "Yes"){
            vaccBool = true;
        }else{
            vaccBool = false;
        }
        int temperance = query.value(8).toInt();
        int trainability = query.value(9).toInt();
        int intelligence = query.value(10).toInt();
        int mischievousness = query.value(11).toInt();
        int socialAttitude = query.value(12).toInt();
        int strangerFriendly = query.value(13).toInt();
        int energy = query.value(14).toInt();
        int childFriendly = query.value(15).toInt();
        int playfulness = query.value(16).toInt();
        int patience = query.value(17).toInt();
        int independence = query.value(18).toInt();
        int obedience = query.value(19).toInt();
        Animal a = Animal(breed,ageYears,ageMonths,gender,vaccBool,name,species,temperance,trainability,intelligence,mischievousness,socialAttitude,strangerFriendly,energy,childFriendly,playfulness,patience,independence,obedience,DOB);
        currentAnimals.push_back(a);

    }
    return currentAnimals;
}

/**
Function: getClients()
in:
out:
return: vector<Clients> containing all of the Clients in the database
purpose: return all animals currently in the database
**/
vector<Client> databaseManager::getClients(){
    QSqlQuery query;
    vector<Client> currentClients;
    query.exec("SELECT * FROM clients");

   while (query.next()){
       QString fName = query.value(0).toString();
       QString lName = query.value(1).toString();
       QString pCode = query.value(2).toString();
       QString cit = query.value(3).toString();
       QString pro = query.value(4).toString();
       QString ad1 = query.value(5).toString();
       QString ad2 = query.value(6).toString();
       QString user = query.value(7).toString();
       QString pass = query.value(8).toString();
       QString ema = query.value(9).toString();
       QString pNum = query.value(10).toString();

       Client a = Client(fName, lName, pCode, cit, pro, user, pass, ema, pNum, ad1, ad2);
       currentClients.push_back(a);

    }
    return currentClients;
}

