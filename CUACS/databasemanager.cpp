#include "databasemanager.h"

databaseManager::databaseManager(const QString& path)
{
animalDB = QSqlDatabase::addDatabase("QSQLITE");
animalDB.setDatabaseName(path);


if (!animalDB.open()){
    cout <<"Error: Failed connection with database";
}else{
    cout << "Successfully connected with database";
}
}

bool databaseManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS animals(breed TEXT, ageYears INTEGER, ageMonths INTEGER, gender TEXT, vaccinated TEXT, name TEXT PRIMARY KEY, DOB INTEGER, species TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'team': one might already exist.";
        success = false;
    }

    return success;
}

//adds an animal to the database
void databaseManager::addAnimal(Animal add){
    QSqlQuery query;
    query.prepare("INSERT INTO animals (breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species) VALUES (:br, :ay, :am, :gen, :vacc, :name, :DOB, :spec)");
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

    if(!query.exec()){
        qDebug()<<query.lastError()<<query.executedQuery();
    }

    cout<<"Added animal to DB\n";
}

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
        Animal a = Animal(breed,ageYears,ageMonths,gender,vaccBool,name,DOB,species);
        currentAnimals.push_back(a);
        cout<<"\nPrinted an animal from tthe database\n";
    }
    return currentAnimals;
}
