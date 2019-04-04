#ifndef CLIENTONLYVIEW_H
#define CLIENTONLYVIEW_H

#include <QMainWindow>
#include <clientmanager.h>
#include <animalmanager.h>
#include <databasemanager.h>
#include <animaldetailedview.h>
#include <vector>
#include <animal.h>
#include <client.h>
#include <QRegExpValidator>
#include <QRegExp>
#include <QString>


namespace Ui {
class ClientOnlyView;
}

class ClientOnlyView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientOnlyView(Client *, QWidget *parent = 0);
    ~ClientOnlyView();

private slots:
    void on_pushButton_clicked();

    void on_editClientBtn_clicked();

private:
    QString fName;
    QString lName;
    QString user;
    Ui::ClientOnlyView *ui;
    ClientManager cm;
    const int Acceptable = QValidator::Acceptable;
    int animalNum;
    AnimalManager am;

    void displayNewAnimal(Animal, int rowNum);
};

#endif // CLIENTONLYVIEW_H
