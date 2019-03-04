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
using namespace std;

namespace Ui {
class CUACSView;
}

class CUACSView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CUACSView(QWidget *parent = 0);
    ~CUACSView();
    void addAnimal();
    bool checkUsername(QString);
private slots:
    void on_addAnimalBtn_clicked();

    void on_addClientBtn_clicked();

    void on_detailedClientsBtn_clicked();

    void on_pushButton_clicked();

private:
    DetailedClientView *detailedView;
    AnimalDetailedView *animalView;
    const int Acceptable = QValidator::Acceptable;
    Ui::CUACSView *ui;
    std::vector<Animal> animals;
    std::vector<Client> clients;
    void displayNewAnimal(Animal, int);
    void displayNewClient(Client, int);
    databaseManager localDB = databaseManager("localStorage.db");
};

#endif // CUACSVIEW_H
