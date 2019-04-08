#ifndef MATCHPAIR_H
#define MATCHPAIR_H

class matchPair{

public:
    matchPair(Client client, Animal animal);
    ~matchPair();

    //Client Attributes
    Client getOwner() const;
    int getOwnerPref() const;
    int getSocialPref() const;
    int getBehavePref() const;
    int getChildPref() const;
    int getStrangerPref() const;

    //Animal Attributes
    Animal getAnimal() const;
    int getTemperament() const;
    int getTrainability() const;
    int getIntelligence() const;
    int getMischievousness() const;
    int getSocialAttitutde() const;
    int getStrangerFriendly() const;
    int getEnergy() const;
    int getChildFriendly() const;
    int getPlayfulness() const;
    int getPatience() const;
    int getIndependence() const;
    int getObedience() const;

private:
    int temperament;
    int trainability;
    int intelligence;
    int mischievousness;
    int socialAttitude;
    int strangerFriendly;
    int energy;
    int childFriendly;
    int playfulness;
    int patience;
    int independence;
    int obedience;

    int ownerControl, ownerRank;
       bool ownPref;
       int sociability, socialRank;
       bool socialPref;
       int behaviour, behaveRank;//10 being very sociable
       bool behavePref;
       int strangerFriendly;
       int childFriendly;//2 is no preference, 1 is not friendly 3 is friendly


}

#endif // MATCHPAIR_H
