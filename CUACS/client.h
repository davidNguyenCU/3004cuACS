#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
using namespace std;


class Client
{
public:

    /*
     *  "ownerCon INTEGER, "
                  "ownRank INTEGER, "
                  "socab INTEGER, "
                  "socRank INTEGER, "
                  "behav INTEGER, "
                  "behavRank INTEGER, "
                  "strangeFriend INTEGER, "
                  "childFriend INTEGER, "
     *
     **/

    Client(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, int ownCon, int ownRank, int socab, int socRank, int behave, int behavRank, int strangeFriend, int childFriend);
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

    int getOwnerControl() const;
    int getOwnerRank() const;
    int getSociability() const;
    int getSocialRank() const;
    int getBehaviour() const;
    int getBehaveRank() const;
    int getStrangerFriendly() const;
    int getChildFriendly() const;
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

   QString email;
   QString phoneNumber;

   int ownerControl, ownerRank;
   bool ownPref;
   int sociability, socialRank;
   bool socialPref;
   int behaviour, behaveRank;//10 being very sociable
   bool behavePref;
   int strangerFriendly;
   int childFriendly;//2 is no preference, 1 is not friendly 3 is friendly


};

#endif // CLIENT_H
