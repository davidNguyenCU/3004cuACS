#ifndef ACM_H
#define ACM_H

#include <map>
#include <vector>

#include "animal.h"
#include "client.h"

class ACM{

public:
    static vector<std::pair<Client, Animal>> runACM(vector<Animal>, vector<Client>, vector<Client> &);    //SHOULD RETURN MAP of CLIENT > (ANIMAL_MATCH)
    static float getCompatibilityIndex(Animal, Client);


    static void printCLIENT(Client C);
    static void printANIMAL(Animal A);
};

#endif
