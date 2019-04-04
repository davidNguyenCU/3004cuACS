#ifndef ANIMALDETAILEDVIEW_H
#define ANIMALDETAILEDVIEW_H

#include <QDialog>
#include <vector>
#include "animal.h"
#include <animalmanager.h>
#include <QTableWidget>

namespace Ui {
class AnimalDetailedView;
}

class AnimalDetailedView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailedView(AnimalManager&, QTableWidget*,bool, QWidget *parent = 0);
    ~AnimalDetailedView();
    void setAnimals();
private slots:
    void on_previousBtn_clicked();

    void on_nextBtn_clicked();

    void on_editBtn_clicked();

private:
    Ui::AnimalDetailedView *ui;
    AnimalManager am;
    QTableWidget *table;
    int index;
    void edit(bool);
    bool editing;
};

#endif // ANIMALDETAILEDVIEW_H
