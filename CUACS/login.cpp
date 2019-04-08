#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    localDB = new databaseManager("localStorage.db");
    localDB->createTable();
    localDB->populateTables();
}

Login::~Login()
{
    delete ui;
}

/**
Function: on_staffBtn_clicked()
in:
out:
return:
purpose: Launches the staff view of the CUACS
**/
void Login::on_staffBtn_clicked()
{
    auto win = new CUACSView(this, localDB);
    win->setAttribute( Qt::WA_DeleteOnClose );
    ui->passTxt->setText("");
    ui->userTxt->setText("");
    win->show();
    this->close();
}

/**
Function: on_clientBtn_clicked()
in:
out:
return:
purpose: Launches the client view of the CUACS
**/
void Login::on_clientBtn_clicked()
{

    ClientManager newClientManager(localDB);
    QString user = ui->userTxt->text();
    QString pass = ui->passTxt->text();
    ui->passTxt->setText("");
    ui->userTxt->setText("");
    Client *c = newClientManager.login(user,pass);

    //If a client with the given credentials exists, launch client view
    if(c){
        auto win = new ClientOnlyView(this, c, localDB);
        win->setAttribute(Qt::WA_DeleteOnClose);
        win->show();
        this->close();
    }
}
