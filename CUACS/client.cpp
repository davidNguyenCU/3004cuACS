#include "client.h"

Client::Client(QString fName,QString lName, QString post, QString town, QString prov, QString user, QString mail,QString pass,  QString phone, QString addLn1, QString addLn2)
{
    fname = fName;
    lname = lName;
    postalCode = post;
    city = town;
    province = prov;
    addressLine1 = addLn1;
    addressLine2 = addLn2;
    username = user;
    email = mail;
    phoneNumber = phone;

    password = pass;
}

QString Client::getAddressLine1() const{return addressLine1;}
QString Client::getAddressLine2() const{return addressLine2;}
QString Client::getfName() const{return fname;}
QString Client::getlName() const{return lname;}
QString Client::getCity() const{return city;}
QString Client::getEmail() const{return email;}
QString Client::getProvince() const{return email;}
QString Client::getPostalCode() const{return email;}
QString Client::getUsername() const{return email;}
QString Client::getPassword() const{return password;}
QString Client::getPhoneNumber() const{return phoneNumber;}

