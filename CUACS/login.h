#ifndef LOGIN_H
#define LOGIN_H
#include "cuacsview.h"
#include <QApplication>
#include <QMainWindow>
#include <clientmanager.h>
#include <databasemanager.h>
#include <clientonlyview.h>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
private slots:
    void on_staffBtn_clicked();

    void on_clientBtn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
