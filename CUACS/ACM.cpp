#include <iostream>
#include "ACM.h"
#include <math.h>

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

    float overallCIX;

    int animalStrangerPref;
    int animalChildPref;

    if(A.getStrangerFriendly() < 3)
        animalStrangerPref = 1;
    else if(A.getStrangerFriendly() > 3)
        animalStrangerPref = 3;
    else
        animalStrangerPref = 2;

    if(A.getChildFriendly() < 3)
        animalChildPref = 1;
    else if(A.getChildFriendly() > 3)
        animalChildPref = 3;
    else
        animalChildPref = 2;

    if(C.getStrangerFriendly() != 2 && C.getStrangerFriendly() != animalStrangerPref)
    {return overallCIX = 0;}

    if(C.getChildFriendly() != 2 && C.getChildFriendly() != animalChildPref)
    {return overallCIX = 0;}

    float ownerControlPref = C.getOwnerControl()/10.0;
    float ownerSocialPref = C.getSociability()/10.0;
    float ownerBehaviorPref = C.getBehaviour()/10.0;

    //Certain scores may be multiplied by a factor to allow their scores to be equivalently scored in comparison to other scores
    float petTrainingScore = ((A.getTrainability()*2) + A.getIntelligence() + A.getObedience())/30.0;
    float petSocialScore = (A.getSocialAttitutde() + A.getPlayfulness() + (A.getEnergy()*2) + A.getIndependence())/40.0 ;
    float petBehaviorScore = (A.getPatience() + (A.getTemperament()*2) + A.getMischievousness())/30.0 ;

    float trainingCI = 1 - fabs(ownerControlPref - petTrainingScore);
    float socialCI = 1 - fabs(ownerSocialPref - petSocialScore);
    float behaviorCI = 1 - fabs(ownerBehaviorPref - petBehaviorScore);

    float ownerRank;
    float behaveRank;
    float socialRank;

    //This gargantuan if statement handles all possible combinations of ranks
    //There's probably a cleaner implementation of this (as this would definitely not be scalable with more
    //attributes, but this will do for now with sufficient complexity
    if(C.getOwnerRank() == C.getBehaveRank() && C.getOwnerRank() == C.getSocialRank()){
        //All ranks being equal
        if(C.getOwnerRank() == 4){ //Handles scenario if all ranks are no preferences
            return overallCIX = 1;
        }
        else{
            ownerRank = 0.33;
            socialRank = 0.33;
            behaveRank = 0.33;
        }
    }
    else if(C.getOwnerRank() != C.getBehaveRank() && C.getBehaveRank() != C.getSocialRank()){
        //All ranks being unequal (and their various combinations)
        if(C.getOwnerRank() == 1)
        {ownerRank = 0.50;}
        if(C.getOwnerRank() == 2)
        {ownerRank = 0.3;}
        if(C.getOwnerRank() == 3)
        {ownerRank = 0.2;}

        if(C.getBehaveRank() == 1)
        {behaveRank = 0.5;}
        if(C.getBehaveRank() == 2)
        {behaveRank = 0.3;}
        if(C.getBehaveRank() == 3)
        {behaveRank = 0.2;}

        if(C.getSocialRank() == 1)
        {socialRank = 0.5;}
        if(C.getSocialRank() == 2)
        {socialRank = 0.3;}
        if(C.getSocialRank() == 3)
        {socialRank = 0.2;}

        //Needed to catch no preference cases here, so here's a big block of code to redundantly catch a bunch of no prefs
        //Handling 1x No Preferences with equal rankings
        if(C.getOwnerRank() == C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.5; behaveRank = 0.5; socialRank = 0;}
        if(C.getSocialRank() == C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.5; socialRank = 0.5;}
        if(C.getOwnerRank() == C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.5; behaveRank = 0; socialRank = 0.5;}

        //Handling 1x No Preferences with non even rankings
        if(C.getOwnerRank() > C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.66; behaveRank = 0.33; socialRank = 0;}
        if(C.getOwnerRank() < C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.33; behaveRank = 0.66; socialRank = 0;}

        if(C.getSocialRank() > C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.33; socialRank = 0.66;}
        if(C.getSocialRank() < C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.66; socialRank = 0.33;}

        if(C.getOwnerRank() > C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.66; behaveRank = 0; socialRank = 0.33;}
        if(C.getOwnerRank() < C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.33; behaveRank = 0; socialRank = 0.66;}

        //Handling 2x No Preferences
        if(C.getOwnerRank() == C.getSocialRank() && C.getSocialRank() == 4)
        {ownerRank = 0; behaveRank = 1; socialRank = 0;}
        if(C.getBehaveRank() == C.getSocialRank() && C.getSocialRank() == 4)
        {ownerRank = 1; behaveRank = 0; socialRank = 0;}
        if(C.getBehaveRank() == C.getOwnerRank() && C.getBehaveRank() == 4)
        {ownerRank = 0; behaveRank = 0; socialRank = 1;}

    }
    else{//Handling all Misc Cases

        //Handling 2x Ranks being the same (with 1x rank being higher than the 2x same ranks)
        if(C.getOwnerRank() == C.getBehaveRank() && C.getSocialRank() > C.getOwnerRank())
        {ownerRank = 0.25; behaveRank = 0.25; socialRank = 0.5;}
        if(C.getSocialRank() == C.getBehaveRank() && C.getOwnerRank() > C.getSocialRank())
        {ownerRank = 0.5; behaveRank = 0.25; socialRank = 0.25;}
        if(C.getOwnerRank() == C.getSocialRank() && C.getBehaveRank() > C.getOwnerRank())
        {ownerRank = 0.25; behaveRank = 0.5; socialRank = 0.25;}

        //Handling 2x ranks being the same (with 1x rank being lower than the 2 same ranks)
        if(C.getOwnerRank() == C.getBehaveRank() && C.getSocialRank() < C.getOwnerRank())
        {ownerRank = 0.4; behaveRank = 0.4; socialRank = 0.2;}
        if(C.getSocialRank() == C.getBehaveRank() && C.getOwnerRank() < C.getSocialRank())
        {ownerRank = 0.2; behaveRank = 0.4; socialRank = 0.4;}
        if(C.getOwnerRank() == C.getSocialRank() && C.getBehaveRank() < C.getOwnerRank())
        {ownerRank = 0.4; behaveRank = 0.2; socialRank = 0.4;}

        //Handling 1x No Preferences with equal rankings
        if(C.getOwnerRank() == C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.5; behaveRank = 0.5; socialRank = 0;}
        if(C.getSocialRank() == C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.5; socialRank = 0.5;}
        if(C.getOwnerRank() == C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.5; behaveRank = 0; socialRank = 0.5;}

        //Handling 1x No Preferences with non even rankings
        if(C.getOwnerRank() > C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.66; behaveRank = 0.33; socialRank = 0;}
        if(C.getOwnerRank() < C.getBehaveRank() && C.getSocialRank() == 4)
        {ownerRank = 0.33; behaveRank = 0.66; socialRank = 0;}

        if(C.getSocialRank() > C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.33; socialRank = 0.66;}
        if(C.getSocialRank() < C.getBehaveRank() && C.getOwnerRank() == 4)
        {ownerRank = 0; behaveRank = 0.66; socialRank = 0.33;}

        if(C.getOwnerRank() > C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.66; behaveRank = 0; socialRank = 0.33;}
        if(C.getOwnerRank() < C.getSocialRank() && C.getBehaveRank() == 4)
        {ownerRank = 0.33; behaveRank = 0; socialRank = 0.66;}

        //Handling 2x No Preferences
        if(C.getOwnerRank() == C.getSocialRank() && C.getSocialRank() == 4)
        {ownerRank = 0; behaveRank = 1; socialRank = 0;}
        if(C.getBehaveRank() == C.getSocialRank() && C.getSocialRank() == 4)
        {ownerRank = 1; behaveRank = 0; socialRank = 0;}
        if(C.getBehaveRank() == C.getOwnerRank() && C.getBehaveRank() == 4)
        {ownerRank = 0; behaveRank = 0; socialRank = 1;}
    }
    overallCIX = (trainingCI*ownerRank) + (behaviorCI*behaveRank) + (socialCI*socialRank);
    if(overallCIX < 0.5) {overallCIX = 0;}

    return overallCIX;
}
