#include "detailedclientview.h"
#include "ui_detailedclientview.h"

DetailedClientView::DetailedClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedClientView)
{
    ui->setupUi(this);
    index = 0;
}

DetailedClientView::~DetailedClientView()
{
    delete ui;
}

/**
Function: setClients
in: A vector of Clients that will be displayed in detail
out:
return:
purpose: Initialize the Clients in the detailed View and display the first Client
**/
void DetailedClientView::setClients(vector<Client> &c){
    clients = c;
    if(clients.size()!=0){
        ui->firstNameLbl->setText(clients[0].getFirstName());
        ui->lastNameLbl->setText(clients[0].getLastName());
        ui->addLn1Lbl->setText(clients[0].getAddressLine1());
        ui->addLn2Lbl->setText(clients[0].getAddressLine2());
        ui->cityLbl->setText(clients[0].getCity());
        ui->emailLbl->setText(clients[0].getEmail());
        ui->usernameLbl->setText(clients[0].getUsername());
        ui->phoneNumberLbl->setText(clients[0].getPhoneNumber());
        ui->provinceLbl->setText(clients[0].getProvince());
        ui->postalCodeLbl->setText(clients[0].getPostalCode());
    }
}

/**
Function: on_nextBtn_clicked()
in:
out:
return:
purpose:Display the next Client or loops back to the beginning when the next button is clicked
**/
void DetailedClientView::on_nextBtn_clicked()
{
    if(index == (clients.size()-1)){
        index = 0;
    }else{
        index+=1;
    }
    ui->firstNameLbl->setText(clients[index].getFirstName());
    ui->lastNameLbl->setText(clients[index].getLastName());
    ui->addLn1Lbl->setText(clients[index].getAddressLine1());
    ui->addLn2Lbl->setText(clients[index].getAddressLine2());
    ui->cityLbl->setText(clients[index].getCity());
    ui->emailLbl->setText(clients[index].getEmail());
    ui->usernameLbl->setText(clients[index].getUsername());
    ui->phoneNumberLbl->setText(clients[index].getPhoneNumber());
    ui->provinceLbl->setText(clients[index].getProvince());
    ui->postalCodeLbl->setText(clients[index].getPostalCode());
}

/**
Function: on_previousBtn_clicked()
in:
out:
return:
purpose: Displays the previous Client or loops back around to the last Client upon clicking the previous button
**/
void DetailedClientView::on_previousBtn_clicked()
{
    if(index == 0){
        index = clients.size()-1;
    }else{
        index-=1;
    }
    ui->firstNameLbl->setText(clients[index].getFirstName());
    ui->lastNameLbl->setText(clients[index].getLastName());
    ui->addLn1Lbl->setText(clients[index].getAddressLine1());
    ui->addLn2Lbl->setText(clients[index].getAddressLine2());
    ui->cityLbl->setText(clients[index].getCity());
    ui->emailLbl->setText(clients[index].getEmail());
    ui->usernameLbl->setText(clients[index].getUsername());
    ui->phoneNumberLbl->setText(clients[index].getPhoneNumber());
    ui->provinceLbl->setText(clients[index].getProvince());
    ui->postalCodeLbl->setText(clients[index].getPostalCode());
}
