#ifndef ANIMALDETAILEDVIEW_H
#define ANIMALDETAILEDVIEW_H

#include <QDialog>
#include <vector>
#include "animal.h"
#include <animalmanager.h>
#include <QTableWidget>
#include "errorinformation.h"

namespace Ui {
class AnimalDetailedView;
}

class AnimalDetailedView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailedView(AnimalManager*, QTableWidget*,bool, QWidget *parent = 0);
    ~AnimalDetailedView();
    void setAnimals();
    void setIndex(int);
private slots:
    void on_previousBtn_clicked();

    void on_nextBtn_clicked();

    void on_editBtn_clicked();

private:
    void update();
    Ui::AnimalDetailedView *ui;
    vector<Animal> animals;
    AnimalManager *am;
    QTableWidget *table;
    int index;
    void edit(bool);
    bool editing;
};

#endif // ANIMALDETAILEDVIEW_H
