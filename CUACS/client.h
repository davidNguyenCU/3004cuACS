#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
using namespace std;


class Client
{
public:

    Client(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString = "");
    QString getFirstName() const;
    QString getLastName() const;
    QString getPostalCode() const;
    QString getCity() const;
    QString getProvince() const;
    QString getAddressLine1() const;
    QString getAddressLine2() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getEmail() const;
    QString getPhoneNumber() const;
private:
   QString firstName;
   QString lastName;

   QString postalCode;
   QString city;
   QString province;

   QString addressLine1;
   QString addressLine2;//this will be an optional field;

   QString username;//this will be the primary key for the user, and each must be unique
   QString password;//This will simply be set to a minimum character count.
   //If we have time, we will be encrypting the passwords using SHA256, in order to have some security

   QString email;
   QString phoneNumber;
};

#endif // CLIENT_H
