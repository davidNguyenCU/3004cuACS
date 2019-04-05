#include "ACM.h"

#define threshold .5


vector<std::pair<Client, Animal>> ACM::runACM(vector<Animal> animals, vector<Client> clients){


    vector<std::pair<Client, Animal>> resultVec = vector<std::pair<Client, Animal>>();  //result vector containing all Client/Animal matches.
    vector<vector<float>> compatArray; //2d vec containing CI's for every Client, Animal pair.
    vector<int> nMatchs = vector<int>();  //Vector containing client, number of animal matches.


    for(int i = 0; i < clients.size(); i++){
        int numMatches = 0;
        for(int j = 0; j < animals.size(); j++){
            compatArray[i][j] = getCompatabilityIndex(animals.at(j), clients.at(i));    //calculate every CI for each Client, Animal pair.
            if(compatArray[i][j] != 0){     //count number of client matches
                numMatches++;
            }
        }
        nMatchs.push_back(numMatches);
        //nMatchs.push_back(std::make_pair(clients.at(i), numMatches));
    }


    while(clients.size() > 0 && animals.size() > 0){

        /* GET INDEX OF CLIENT WITH MIN MATCHES */
        int minClientIndex = 0;
        for(int i = 0; i < compatArray.size(); i++){
            if(nMatchs.at(i) < nMatchs.at(minClientIndex)){
                minClientIndex = i;
            }
        }

        //TODO OPTIMIZE
        if (nMatchs.at(minClientIndex) != 0){   //IF CLIENT HAS MATCHES
            int minAnimalIndex = -1;
            for(int i = 0; i < compatArray.at(minClientIndex).size(); i++){
                if(compatArray.at(minClientIndex).at(i) != 0){  //ANIMAL FOUND, BREAK AND ADD
                    minAnimalIndex = i;
                    break;
                }
            }

            resultVec.push_back(std::make_pair(clients.at(minClientIndex), animals.at(minAnimalIndex)));
            animals.erase(animals.begin() + minAnimalIndex);

        }else{  //IF CLIENT HAS NO MATCHES, do nothing
            // Create empty match and add to result
//            resultVec.push_back(std::make_pair(clients.at(minClientIndex), NULL));
        }

        //REMOVE CLIENT
        nMatchs.erase(nMatchs.begin() + minClientIndex);
        clients.erase(clients.begin() + minClientIndex);

    }


    return resultVec;


}

float ACM::getCompatabilityIndex(Animal A, Client C){
    return ((float)A.getIndependence())*.3 + ((float)C.getBehaviour())*.3;
/*
    //see d2 documentation

    float ownerControlPref = C.getOwnerControlPref;
    float ownerSocialPref = C.getPetSocialPref;
    float ownerBehaviorPref = C.getBehaviorPref;

    int strangerFriendlyRank = C.getStrangerPref;
    int childFriendlyRank = C.getChildFriendlyPref;

    //Certain scores may be multiplied by a factor to allow their scores to be equivalently scored in comparison to other scores


    float petTrainingScore = ((A.getTrainability()*2) + A.getIntelligence() + A.getObedience())/30;

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
    int getID() const;

    float petSocialScore = (A.getSocialAbility + A.getPlayfulness + (A.getActivity*2) + A.getDependence)/40 ;

    float petBehaviorScore = (A.getTolerance + (A.getTemperament*2) + A.getMischeviousness)/30 ;

    float trainingCI = 100% - |ownerControlPref - petTrainingScore| ;
    float socialCI = 100% - |ownerSocialPref - petSocialScore| ;
    float behaviorCI = 100% - |ownerBehaviorPref - petBehaviorScore| ;

    float overallCIX = (trainingCI*C.getTrainingRank) + (socialCI*C.getSocialRank) + (behaviorCI*C.getBehaviorRank)

    if(strangerFriendlyRank != 2 && strangerFriendlyRank != A.getStrangerFriendliness)
    {overallCIX = 0;}

    if(childFriendlyRank != 2 && childFriendlyRank != A.getChildFriendliness)
    {overallCIX = 0;}

    if(CI < threshold){ CI = 0;}

    return overallCIX;
    */

}
