#include "errorinformation.h"
#include "ui_errorinformation.h"

/**
  * This class is just used to display the errors when validating user input
  */
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
