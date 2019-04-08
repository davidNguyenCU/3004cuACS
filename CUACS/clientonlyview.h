#ifndef CLIENTONLYVIEW_H
#define CLIENTONLYVIEW_H


#include <QApplication>
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
#include "login.h"

using namespace std;

namespace Ui {
class ClientOnlyView;
}

class ClientOnlyView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientOnlyView(QMainWindow *lg, Client *, databaseManager*, QWidget *parent = 0);
    ~ClientOnlyView();

private slots:
    void on_pushButton_clicked();

    void on_editClientBtn_clicked();

    void logout();

    void exitFunc();

public slots:
    void setSelectedAnimal(int, int, int, int);

private:
    QMainWindow *login;
    QAction *log;
    QAction *exit;
    QString fName;
    QString lName;
    QString user;
    Ui::ClientOnlyView *ui;
    ClientManager cm;
    const int Acceptable = QValidator::Acceptable;
    int animalNum;
    AnimalManager am;
    AnimalDetailedView *view;

    void displayNewAnimal(Animal, int rowNum);
};

#endif // CLIENTONLYVIEW_H
