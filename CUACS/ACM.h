#ifndef ACM_H
#define ACM_H

#include <map>
#include <vector>

#include "animal.h"
#include "client.h"

class ACM{

public:
    static vector<std::pair<Client, Animal>> runACM(vector<Animal>, vector<Client>);
    static float getCompatabilityIndex(Animal, Client);

};

#endif
