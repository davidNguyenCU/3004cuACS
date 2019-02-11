#ifndef ANIMAL_H
#define ANIMAL_H
#include<QString>
using namespace std;

class Animal
{
public:
    Animal(QString, int, int, QString, bool, QString, QString, QString = "UNKNOWN");
    ~Animal();
    /*
    void setDOB(QString);
    void setBreed(QString);
    void setGender(QString);
    void setSpecies(QString);
    void setName(QString);
    void setAgeYears(int);
    void setAgeMonths(int);
    void setVaccinated(int);
    */
    //Getter Functions
    QString getBreed() const;
    QString getGender() const;
    QString getSpecies() const;
    QString getName() const;
    QString getDOB() const;

    int getMonths() const;
    int getYears() const;
    bool isVaccinated() const;


private:
    int ageYears;
    int ageMonths;
    bool vaccinated;
    QString gender;
    QString name;
    QString dateOfBirth;//only to be filled out if available
    QString breed;
    QString species;//to be abstracted in later versions

    /*
    //Twelve unique attributes needed
    int monthlyCost;
    double friendliness;//marked on a scale of 1-10
    int trainability;
    int energy;
    */

};

#endif // ANIMAL_H
