#ifndef CUACSVIEW_H
#define CUACSVIEW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include <QRegExp>
#include "animal.h"
#include "databasemanager.h"
#include "client.h"
#include "detailedclientview.h"
#include "animaldetailedview.h"
#include "clientmanager.h"
#include "animalmanager.h"
using namespace std;

namespace Ui {
class CUACSView;
}

class CUACSView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CUACSView(databaseManager *db, QWidget *parent = 0);
    ~CUACSView();
    void addAnimal();
    bool checkUsername(QString);
private slots:
    void on_addAnimalBtn_clicked();

    void on_addClientBtn_clicked();

    void on_detailedClientsBtn_clicked();

    void on_pushButton_clicked();

    void on_runACMbutton_clicked();

private:
    int clientNum;
    int animalNum;
    std::vector<Client> clients;
    std::vector<Animal> animals;
    DetailedClientView *detailedView;
    AnimalDetailedView *animalView;
    const int Acceptable = QValidator::Acceptable;
    Ui::CUACSView *ui;
    void displayNewAnimal(Animal, int);
    void editDisplayedAnimal(Animal, int);
    void displayNewClient(Client, int);
    ClientManager manageClients;
    AnimalManager manageAnimals;
};

#endif // CUACSVIEW_H
