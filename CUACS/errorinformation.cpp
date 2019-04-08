#include "errorinformation.h"
#include "ui_errorinformation.h"

errorInformation::errorInformation(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorInformation)
{
    ui->setupUi(this);
    ui->errorLabel->setText(str);
}

errorInformation::~errorInformation()
{
    delete ui;
}
