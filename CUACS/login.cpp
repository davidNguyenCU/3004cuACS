#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    localDB = new databaseManager("localStorage.db");
    localDB->createTable();
}

Login::~Login()
{
    delete ui;
}
void Login::on_staffBtn_clicked()
{
    auto win = new CUACSView();
    win->setAttribute( Qt::WA_DeleteOnClose );
    win->show();
    this->close();
}

void Login::on_clientBtn_clicked()
{

    ClientManager newClientManager(localDB);
    QString user = ui->userTxt->text();
    QString pass = ui->passTxt->text();
    Client *c = newClientManager.login(user,pass);
    if(c){
        auto win = new ClientOnlyView(c, localDB);
        win->setAttribute(Qt::WA_DeleteOnClose);
        win->show();
        this->close();
    }
}
