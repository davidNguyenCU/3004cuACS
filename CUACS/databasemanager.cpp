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
Function: createTable()
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
                  "id INTEGER, "
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
    //int ownCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend;
    query.prepare("CREATE TABLE IF NOT EXISTS clients("
                  "firstName TEXT, "
                  "lastName TEXT, "
                  "postalCode TEXT, "
                  "city TEXT, "
                  "province TEXT, "
                  "addressLine1 TEXT, "
                  "addressLine2 TEXT, "
                  "username TEXT, "
                  "password TEXT, "
                  "email TEXT, "
                  "phoneNumber TEXT, "
                  "ownerCon INTEGER, "
                  "ownRank INTEGER, "
                  "socab INTEGER, "
                  "socRank INTEGER, "
                  "behav INTEGER, "
                  "behavRank INTEGER, "
                  "strangeFriend INTEGER, "
                  "childFriend INTEGER, "
                  "primary key (username));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'clients': one might already exist.";
        success = false;
    }

    return success;
}

/**
Function: populateTables
in:
out:
return:
purpose: Fills the database tables with 25 animals and 5 clients
**/
void databaseManager::populateTables()
{
     QSqlQuery query;
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(1, 'Australian Shepherd', 11, 8, 'Male', 'Yes','Buddy','UNKNOWN','Dog',5, 2, 1, 8, 9, 4, 2, 5, 5, 4, 7, 9)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(2, 'Maine Coon', 5, 6, 'Female', 'Yes','Delilah','UNKNOWN','Cat',1, 4, 2, 1, 10, 2, 3, 2, 8, 10, 5, 1 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(3, 'Ragdoll', 1, 6, 'Female', 'Yes','Carly','UNKNOWN','Cat',3, 2, 3, 6, 3, 5, 4, 2, 1, 4, 3, 10 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(4, 'Yellow Box', 1, 1, 'Male', 'No','Leonard','2018-01-14','Turtle',3, 3, 4, 2, 3, 3, 4, 2, 2, 5, 2, 8)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(5, 'Canary', 0, 10, 'Female', 'Yes','Clementine','UNKNOWN','Bird',1, 3, 5, 5, 2, 3, 1, 1, 6, 5, 10, 4 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(6, 'Pug', 1, 8, 'Female', 'Yes','Cherry','2017-08-19','Dog',3, 4, 6, 10, 6, 2, 5, 1, 4, 2, 1, 7 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(7, 'Shih Tzu', 0, 8, 'Female', 'Yes','Sam','2017-08-28','Dog',2, 3, 7, 6, 1, 2, 2, 4, 3, 10, 5, 4)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(8, 'Tree', 2, 8, 'Male', 'No','Froppy','2017-08-23','Frog',1, 5, 8, 1, 9, 4, 5, 3, 4, 10, 7, 8)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(9, 'Woodpecker', 2, 2, 'Male', 'No','Woody','2017-02-05','Bird',4, 2, 9, 4, 1, 1, 4, 2, 10, 7, 10, 2)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(10, 'Snapping', 3, 1, 'Female', 'Yes','Wanda','2016-08-06','Turtle',5, 2, 10, 8, 6, 3, 2, 4, 7, 5, 10, 4)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(11, 'Golden', 1, 2, 'Female', 'Yes','Hamatora','UNKNOWN','Hamster',1, 1, 1, 5, 7, 1, 1, 1, 9, 8, 3, 2)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(12, 'Parrot', 0, 4, 'Male', 'Yes','Polly','2018-08-02','Bird',5, 4, 2, 4, 10, 3, 2, 1, 2, 9, 10, 6)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(13, 'Scottish Fold', 4, 4, 'Male', 'Yes','Albert','2015-04-10','Cat',1, 2, 3, 1, 6, 3, 4, 5, 10, 6, 1, 7)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(14, 'Dobermann', 5, 8, 'Male', 'Yes','Archie','2014-02-28','Dog',4, 4, 4, 5, 6, 4, 4, 4, 7, 6, 4, 2)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(15, 'Texel', 1, 6, 'Male', 'Yes','Doug','2018-03-03','Guinea Pig',1, 2, 5, 10, 3, 1, 2, 1, 4, 7, 9, 7 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(16, 'Greyhound', 7, 8, 'Female', 'No','Mary Jane','UNKNOWN','Dog',2, 2, 6, 3, 5, 2, 2, 2, 7, 6, 10, 1)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(17, 'Bengal', 3, 6, 'Male', 'No','Steve','2016-06-06','Cat', 2, 3, 7, 2, 4, 2, 3, 2, 6, 3, 8, 3)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(18, 'Glass', 4, 8, 'Male', 'Yes','Hopper','2015-08-19','Frog', 3, 4, 8, 8, 7, 3, 4, 3, 5, 8, 1, 5 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(19, 'Softshell', 8, 8, 'Male', 'No','Mikey','UNKNOWN','Turtle', 5, 5, 9, 6, 8, 5, 5, 5, 7, 9, 2, 3 )");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(20, 'Finch', 3, 1, 'Female', 'No','Brian','2016-07-17','Bird', 4, 5, 10, 8, 6, 4, 5, 4, 7, 10, 4, 9)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(21, 'Chinese', 4, 2, 'Male', 'Yes','Splinter','2015-12-09','Hamster', 1, 3, 1, 10, 4, 1, 3, 1, 9, 2, 10, 7)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(22, 'Persian', 0, 5, 'Male', 'Yes','Hairball','2018-10-29','Cat', 3, 3, 2, 10, 7, 3, 3, 3, 1, 7, 6, 8)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(23, 'Husky', 3, 7, 'Male', 'No','Moon Moon','2016-01-11','Dog', 5, 4, 3, 3, 7, 4, 5, 5, 5, 3, 1, 4)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(24, 'African Dwarf', 2, 8, 'Male', 'No','Kermit','2017-04-25','Frog', 4, 2, 4, 10, 9, 1, 2, 3, 10, 8, 10, 1)");
    query.exec("INSERT OR REPLACE INTO animals(id, breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience)"
     "VALUES(25, 'Penguin', 3, 7, 'Female', 'Yes','Pengu','UNKNOWN','Bird', 3, 2, 5, 3, 9, 4, 3, 1, 8, 2, 4, 10)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
     "VALUES ('Joseph', 'Hugh', 'K1S2Y3', 'Ottawa', 'ON', '956 Aylmer Ave.', '', 'JHug', 'secret123', 'J_Hugh@yahoo.com', '(357)-846-9513',10,3,10,3,10,3,3,3)");
    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
     "VALUES ('Sarah', 'Marceline', 'L6N0M3', 'Oakville', 'ON', '831 Steeles Ave.', '', 'SMar', 'notsoSecret547', 'S_Lineh@gmail.com', '(905)-476-9842',1,4,10,3,3,1,1,1)");
    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
     "VALUES ('Johann', 'Bach', 'R5R5P5', 'Brandon', 'MB', '52 Park Ave.', '', 'PianistBach', 'P1an0', 'Bach@hotmail.com', '(578)-555-9891',3,4,6,2,9,3,1,3)");
    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
     "VALUES ('Mattheus', 'Simpson', 'L5R1E3', 'Saskatoon', 'SK', '185 Applby Dr.', '', 'MSimp', 'password123', 'SimpsonM@hotmail.com', '(781)-159-2233',10,3,5,1,8,2,2,2)");
    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
     "VALUES ('Miles', 'Parker', 'C4T2Q5', 'Halifax', 'NS', '789 Summit St.', '', 'MParker', 'notSpider', 'Parker@gmail.com', '(678)-567-3287',7,2,10,3,4,1,3,3)");


    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Haya', 'Mac', 'K1A0L9', 'Ottawa', 'ON', '3910 Park Ave.', '', 'HiYah', 'Apple_51', 'H_Mac@gmail.com', '(666)-005-5137',5,2,9,3,1,1,1,1)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Patricia', 'Whittle', 'K2J0K6', 'Ottawa', 'ON', '4 White Hill Ave.', '', 'PatWhite', 'KrustyKrab456', 'P_Whittle@yahoo.com', '(007)-114-3692',1,1,1,1,1,1,1,1)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Saul', 'Cartwright', 'K1K4R4', 'Ottawa', 'ON', '41 Calavaires Ave.', '', 'BetterCallSaul', 'BluePower159', 'S_Cartwright@hotmail.com', '(989)-573-4825',2,2,2,2,2,2,2,2)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Hanan', 'Figueroa', 'L0P1N0', 'Brampton', 'ON', '321 Fake St.', '', 'HanFig', 'Montana89', 'H_Figueroa@live.com', '(573)-410-3722',3,3,3,3,3,3,3,3)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Zahra', 'Corbett', 'M4C1M5', 'Toronto', 'ON', '1 Horsey Dr.', '', 'Zahahahaha', 'CheckIt78', 'Z_Corbett@gmail.com', '(101)-628-2047',6,2,6,2,6,2,1,3)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Marnie', 'Francis', 'R0K0R0', 'Brandon', 'MB', '2 Quack St.', '', 'MarFrac', 'DeadPo0l', 'M_Francis@yahoo.com', '(209)-820-4782',8,2,5,1,1,2,2,1)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Shelly', 'Jones', 'P7A0A4', 'Thunder Bay', 'ON', '42 Leblanc Ave.', '', 'SJones', 'Gr8B8M8', 'S_Jones@hotmail.com', '(098)-665-0856',2,1,8,1,7,3,1,2)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Imaan', 'Chambers', 'R0K2A0', 'Shilo', 'MB', '420 Ramos Dr.', '', 'ImChamber', 'SnakeDown87', 'I_Chambers@live.com', '(427)-806-6583',1,3,1,3,1,3,2,2)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Asad', 'Bryan', 'T9M0B4', 'Cold Lake', 'AB', '69 Geiler Cres.', '', 'sadBryan', 'AsdBrY57', 'A_Bryan@gmail.com', '(333)-821-9143',8,1,3,1,4,1,3,3)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Giorgia', 'Welch', 'T1Y1A2', 'Calgary', 'AB', '45 Grickites Dr.', '', 'GeorgeWatch', 'NoWalch92', 'G_Welch@yahoo.com', '(357)-996-9919',5,3,5,3,5,1,3,1)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Aysha', 'Tierney', 'V5K0B2', 'Vancouver', 'BC', '98 Nguyen Ave.', '', 'AsayaTear', 'SadMissSad91', 'A_Tierney@hotmail.com', '(217)-020-0010',2,2,1,3,10,1,2,3)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Polly ', 'Walmsley', 'T5A0A7', 'Edmonton', 'AB', '56 MacDonald Blvd.', '', 'PollyWantsACracker', 'BadB1rd87', 'P_Walmsley@live.com', '(227)-006-9018',6,3,4,2,5,1,3,2)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Julius', 'Klein', 'C1A0A1', 'Charlottetown', 'PE', '7331 Khurshid Dr.', '', 'JCeasar', 'noFriends001', 'J_Klein@gmail.com', '(256)-826-4414',5,1,10,3,6,2,2,2)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Ella', 'Mason', 'G1B1K1', 'Quebec City', 'QC', '38 Rodriques Ave.', '', 'EllaEnchanted', 'NoGodMother159', 'E_Mason@yahoo.com', '(111)-111-1111',7,1,8,2,9,3,1,3)");

    query.exec("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
        "VALUES ('Gregg', 'Millington', 'H1A4K2', 'Montreal', 'QC', '79 Pawley St.', '', 'GreggoryMill', 'Milling147', 'G_Millington@hotmail.com', '(626)-626-6262',8,1,6,2,10,2,1,1)");



}

void databaseManager::updateAnimal(Animal add){
    QSqlQuery query;
    query.prepare("REPLACE INTO animals (breed, ageYears, ageMonths, gender, vaccinated, name, DOB, species, temperament, trainability, intelligence, mischievousness, socialAttitude, strangerFriendly, energy, childFriendly, playfullness, patience, independence, obedience) "
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
Function: addAnimal(Animal)
in: Animal add to be inserted in to the database
out:
return: void
purpose: Adds a given animal to the SQL Database
**/

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
    query.prepare("INSERT OR REPLACE INTO clients(firstName, lastName, postalCode, city, province, addressLine1, addressLine2, username, password, email, phoneNumber, ownerCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend) "
                  "VALUES (:fName, :lName, :pCode, :cit, :pro, :ad1, :ad2, :user, :pass, :ema, :pNum, :oc, :or, :soc, :sr, :bhv, :bhvRank, :strFr, :child)");
    query.bindValue(":fName",add.getFirstName());
    query.bindValue(":lName",add.getLastName());
    query.bindValue(":pCode",add.getPostalCode());
    query.bindValue(":cit",add.getCity());
    query.bindValue(":pro",add.getProvince());
    query.bindValue(":ad1",add.getAddressLine1());
    query.bindValue(":ad2",add.getAddressLine2());
    query.bindValue(":user",add.getUsername());
    query.bindValue(":pass",add.getPassword());
    query.bindValue(":ema",add.getEmail());
    query.bindValue(":pNum",add.getPhoneNumber());
    query.bindValue(":oc", add.getOwnerControl());
    query.bindValue(":or", add.getOwnerRank());
    query.bindValue(":soc", add.getSociability());
    query.bindValue(":sr", add.getSocialRank());
    query.bindValue(":bhv", add.getBehaviour());
    query.bindValue(":bhvRank", add.getBehaveRank());
    query.bindValue(":strFr", add.getStrangerFriendly());
    query.bindValue("child", add.getChildFriendly());

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
        int id = query.value(0).toInt();
        QString breed = query.value(1).toString();
        int ageYears = query.value(2).toInt();
        int ageMonths = query.value(3).toInt();
        QString gender = query.value(4).toString();
        QString vaccString = query.value(5).toString();
        QString name = query.value(6).toString();
        QString DOB = query.value(7).toString();
        QString species = query.value(8).toString();
        bool vaccBool;
        if(vaccString == "Yes"){
            vaccBool = true;
        }else{
            vaccBool = false;
        }
        int temperance = query.value(9).toInt();
        int trainability = query.value(10).toInt();
        int intelligence = query.value(11).toInt();
        int mischievousness = query.value(12).toInt();
        int socialAttitude = query.value(13).toInt();
        int strangerFriendly = query.value(14).toInt();
        int energy = query.value(15).toInt();
        int childFriendly = query.value(16).toInt();
        int playfulness = query.value(17).toInt();
        int patience = query.value(18).toInt();
        int independence = query.value(19).toInt();
        int obedience = query.value(20).toInt();
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
       QString pass = query.value(9).toString();
       QString ema = query.value(8).toString();
       QString pNum = query.value(10).toString();
       int ownCon, ownRank, socab, socRank, behav, behavRank, strangeFriend, childFriend;
       ownCon = query.value(11).toInt();
       ownRank = query.value(12).toInt();
       socab = query.value(13).toInt();
       socRank = query.value(14).toInt();
       behav = query.value(15).toInt();
       behavRank = query.value(16).toInt();
       strangeFriend = query.value(17).toInt();
       childFriend = query.value(18).toInt();

       Client a = Client(fName, lName, pCode, cit, pro, user, pass, ema, pNum, ad1, ad2, ownCon, ownRank, socab, socRank,behav, behavRank,strangeFriend, childFriend);
       currentClients.push_back(a);

    }
    return currentClients;
}

