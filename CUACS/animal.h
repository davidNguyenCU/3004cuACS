#ifndef ANIMAL_H
#define ANIMAL_H
#include<QString>
using namespace std;

class Animal
{
public:
    //This is the basic constructor that is to be used when creating a new animal
    //This constructor does not contain any of the algorithm matching attributes
    Animal(int, QString, int, int, QString, bool, QString, QString, QString = "UNKNOWN");

    //This constructor can be used to create a fully detailed animal profile
    Animal(int, QString, int, int, QString, bool, QString, QString, int, int, int, int, int, int, int, int, int, int, int, int, QString = "UNKNOWN");


    ~Animal();

    //Getter Functions
    QString getBreed() const;
    QString getGender() const;
    QString getSpecies() const;
    QString getName() const;
    QString getDOB() const;

    int getMonths() const;
    int getYears() const;
    bool isVaccinated() const;

    int getTemperament() const;
    int getTrainability() const;
    int getIntelligence() const;
    int getMischievousness() const;
    int getSocialAttitutde() const;
    int getStrangerFriendly() const;
    int getEnergy() const;
    int getChildFriendly() const;
    int getPlayfulness() const;
    int getPatience() const;
    int getIndependence() const;
    int getObedience() const;
    int getID() const;
    void setVacc(bool);
    void setID(int);
    void setYrs(int);
    void setMonths(int);
    void setSocialAttitude(int);
    void setEnergy(int);
    void setIndependence(int);
    void setIntelligence(int);
    void setMisc(int);
    void setObedience(int);
    void setPatience(int);
    void setPlay(int);
    void setStrange(int);
    void setChild(int);
    void setTemp(int);
    void setTrain(int);

private:
    int ageYears;
    int ageMonths;
    bool vaccinated;
    QString gender;
    QString name;
    QString dateOfBirth;//only to be filled out if available
    QString breed;
    QString species;//to be abstracted in later versions

    //This is to be used as the ID for the animal when accessing the database
    int ID;

    //These are the attributes that will be used by the algorithm in order to match animals with client
    int temperament;
    int trainability;
    int intelligence;
    int mischievousness;
    int socialAttitude;
    int strangerFriendly;
    int energy;
    int childFriendly;
    int playfulness;
    int patience;
    int independence;
    int obedience;

};

#endif // ANIMAL_H
