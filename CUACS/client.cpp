#include "client.h"

Client::Client(QString fName, QString lName, QString post, QString town, QString prov, QString user, QString mail,QString pass,  QString phone, QString addLn1, QString addLn2, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank,int strangeFriend, int childFriend )
{
    firstName = fName;
    lastName = lName;
    postalCode = post;
    city = town;
    province = prov;
    addressLine1 = addLn1;
    addressLine2 = addLn2;
    username = user;
    email = mail;
    phoneNumber = phone;
    password = pass;

    //Rank of 4 == no preference
    ownerControl = ownCon;
    ownerRank = ownRank;
    if(ownerRank == 4){
        ownPref = false;
    }else{
        ownPref = true;
    }

    sociability = socab;
    socialRank = socRank;
    if(socialRank==4){
        socialPref = false;
    }else{
        socialPref = true;
    }

    behaviour = behave;
    behaveRank = behavRank;
    if(behaveRank == 4){
        behavePref = false;
    }else{
        behavePref = true;
    }

    //value of 2 == no preference
    strangerFriendly = strangeFriend;
    childFriendly = childFriend;


}
//Getter functions for the client
QString Client::getAddressLine1() const{return addressLine1;}
QString Client::getAddressLine2() const{return addressLine2;}
QString Client::getFirstName() const{return firstName;}
QString Client::getLastName() const{return lastName;}
QString Client::getCity() const{return city;}
QString Client::getEmail() const{return email;}
QString Client::getProvince() const{return province;}
QString Client::getPostalCode() const{return postalCode;}
QString Client::getUsername() const{return username;}
QString Client::getPassword() const{return password;}
QString Client::getPhoneNumber() const {return phoneNumber;}
int Client::getOwnerControl() const{return ownerControl;}
int Client::getOwnerRank() const {return ownerRank;}
int Client::getBehaviour() const {return behaviour;}
int Client::getBehaveRank() const{return behaveRank;}
int Client::getSociability() const{return sociability;}
int Client::getSocialRank() const {return socialRank;}
int Client::getChildFriendly() const {return childFriendly;}
int Client::getStrangerFriendly() const {return strangerFriendly;}

