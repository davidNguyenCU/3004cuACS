#ifndef CUACSVIEW_H
#define CUACSVIEW_H

#include <QMainWindow>
#include "animal.h"
#include "databasemanager.h"
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
private slots:
    void on_addAnimalBtn_clicked();

private:
    Ui::CUACSView *ui;
    std::vector<Animal> animals;
    void displayNewAnimal(Animal);
    databaseManager animalDB = databaseManager("../Desktop/3004cuACS-addedSQLDatabase/build-CUACS-Desktop-Debug/animals.db");
};

#endif // CUACSVIEW_H
