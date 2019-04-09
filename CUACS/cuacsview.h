#ifndef CUACSVIEW_H
#define CUACSVIEW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include <QRegExp>
#include <QAction>
#include "animal.h"
#include "databasemanager.h"
#include "client.h"
#include "detailedclientview.h"
#include "animaldetailedview.h"
#include "detailedmatchesview.h"
#include "clientmanager.h"
#include "animalmanager.h"
#include "login.h"
#include "errorinformation.h"
#include <QHeaderView>

using namespace std;

namespace Ui {
class CUACSView;
}

class CUACSView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CUACSView(QMainWindow *lg, databaseManager *db, QWidget *parent = 0);
    ~CUACSView();
    void addAnimal();
    bool checkUsername(QString);
private slots:
    void on_addAnimalBtn_clicked();

    void on_addClientBtn_clicked();

    void on_detailedClientsBtn_clicked();

    void on_pushButton_clicked();

    void on_runACMbutton_clicked();

    void on_detailMatchButton_clicked();

    void logout();
    void exitFunc();

public slots:
    void setSelectedClient(int, int, int, int);
    void setSelectedAnimal(int, int, int, int);
    void setSelectedMatch(int, int, int, int);

private:
    QMainWindow *l;
    int clientNum;
    int animalNum;
    QAction *log;
    QAction *quit;
    std::vector<Client> clients;
    std::vector<Animal> animals;
    DetailedClientView *detailedView;
    AnimalDetailedView *animalView;
    DetailedMatchesView *detailMatches;
    const int Acceptable = QValidator::Acceptable;
    Ui::CUACSView *ui;
    void displayNewAnimal(Animal, int);
    void editDisplayedAnimal(Animal, int);
    void displayNewClient(Client, int);
    void displayACMResults(vector<std::pair<Client, Animal>> animalClientPairs, vector<Client> nonMatches);
    ClientManager manageClients;
    AnimalManager manageAnimals;
};

#endif // CUACSVIEW_H
