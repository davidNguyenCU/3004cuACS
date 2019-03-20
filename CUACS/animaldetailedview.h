#ifndef ANIMALDETAILEDVIEW_H
#define ANIMALDETAILEDVIEW_H

#include <QDialog>
#include <vector>
#include "animal.h"

namespace Ui {
class AnimalDetailedView;
}

class AnimalDetailedView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailedView(QWidget *parent = 0);
    ~AnimalDetailedView();
    void setAnimals(vector<Animal>);
private slots:
    void on_previousBtn_clicked();

    void on_nextBtn_clicked();

private:
    Ui::AnimalDetailedView *ui;
    vector<Animal> animals;
    int index;
};

#endif // ANIMALDETAILEDVIEW_H
