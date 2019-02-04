#ifndef CUACSVIEW_H
#define CUACSVIEW_H

#include <QMainWindow>
#include "animal.h"

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
};

#endif // CUACSVIEW_H
