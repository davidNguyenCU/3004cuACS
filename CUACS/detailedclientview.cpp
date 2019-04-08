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

void DetailedClientView::setIndex(int i){index = i;}

/**
Function: setClients
in: A vector of Clients that will be displayed in detail
out:
return:
purpose: Initialize the Clients in the detailed View and display the first Client
**/
void DetailedClientView::setClients(vector<Client> c){
    clients = c;
    if(clients.size()!=0){
        update();
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
    update();
}


/**
Function: update()
in:
out:
return:
purpose: Update the detailed client display, displaying te client at the given index in the clients vector
**/
void DetailedClientView::update(){
    //set the labels to display the client at the given information
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
    ui->trainLbl->setText(QString::number(clients[index].getOwnerControl()));
    ui->socLbl->setText(QString::number(clients[index].getSociability()));
    ui->tempLbl->setText(QString::number(clients[index].getBehaviour()));

    //Convert the int value stored to a string corresponding to the value
    int child = clients[index].getChildFriendly();
    QString childText;
    if(child ==1){
        childText = "Not child friendly.";
    }else if (child == 2){
        childText = "No preference.";
    }else{
        childText = "Must be child friendly.";
    }
    ui->childLbl->setText(childText);

    //Convert the int value stored to a string corresponding to the value
    int strange = clients[index].getStrangerFriendly();
    QString stranger;
    if(strange == 1){
        stranger = "Not stranger friendly.";
    }else if (strange == 2){
        stranger =  "No preference.";
    }else{
        stranger = "Must be stranger friendly.";
    }
    ui->strangeLbl->setText(stranger);


    //Display the value for the different ranks, or display No preference
    int ownRank, socRank, bhvRank;
    ownRank = clients[index].getOwnerRank();
    if (ownRank == 4){
        ui->trainRank->setText("No preference.");
    }else{
        ui->trainRank->setText(QString::number(ownRank));
    }
    socRank = clients[index].getSocialRank();
    if(socRank != 4){
        ui->socRank->setText(QString::number(socRank));
    }else{
        ui->socRank->setText("No preference.");
    }
    bhvRank = clients[index].getBehaveRank();
    if(bhvRank != 4){
        ui->tempRank->setText(QString::number(bhvRank));
    }else{
        ui->tempRank->setText("No preference.");
    }

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
    update();
}
