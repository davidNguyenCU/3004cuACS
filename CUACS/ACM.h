#ifndef ACM_H
#define ACM_H

#include <map>
#include <vector>

#include "animal.h"
#include "client.h"

class ACM{

public:
    vector<std::pair<Client, Animal>> runACM(vector<Animal>, vector<Client>);
    float getCompatabilityIndex(Animal, Client);

};

#endif
