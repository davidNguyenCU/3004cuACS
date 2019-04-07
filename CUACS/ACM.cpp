#include <iostream>
#include "ACM.h"
#include <math.h>

#define threshold .5


vector<std::pair<Client, Animal>> ACM::runACM(vector<Animal> animals, vector<Client> clients){
    std::cout << "ACM BEGIN" <<std::endl;

    vector<std::pair<Client, Animal>> resultVec = vector<std::pair<Client, Animal>>();  //result vector containing all Client/Animal matches.
    vector<vector<float>> compatArray = vector<vector<float>>(); //2d vec containing CI's for every Client, Animal pair.
    vector<int> nMatchs = vector<int>();  //Vector containing client, number of animal matches.


    std::cout << "Running ACM on " << clients.size() << " clients, and " << animals.size() << " animals. "<<std::endl;


    bool FLAG_PRINT_DEBUG = false;
    bool FLAG_PRINT_INITIAL_INFO = true;
    bool FLAG_PRINT_END_MATCHES = true;
    if(FLAG_PRINT_INITIAL_INFO){
        for(uint i = 0; i < clients.size(); i++){
            printCLIENT(clients.at(i));
        }
        std::cout << "=====================================" << std::endl;
        for(uint i = 0; i < animals.size(); i++){
            printANIMAL(animals.at(i));
        }
    }


    for(uint i = 0; i < clients.size(); i++){
        if(FLAG_PRINT_DEBUG)
            std::cout << "CLIENT "<< i << " - "<< clients.at(i).getFirstName().toStdString() <<std::endl;


        int numMatches = 0;
        vector<float> matches = vector<float>();

        //calculate every CI for each Client, Animal pair.
        for(uint j = 0; j < animals.size(); j++){
            float compatability = getCompatabilityIndex(animals.at(j), clients.at(i));
            if(compatability != 0){     //count number of client matches
                numMatches++;
            }

            if(FLAG_PRINT_DEBUG)
                std::cout << "  "<< compatability;

            matches.push_back(compatability);
        }
        nMatchs.push_back(numMatches);
        compatArray.push_back(matches);

        if(FLAG_PRINT_DEBUG)
            std::cout << std::endl;
    }



    if(FLAG_PRINT_DEBUG)
        std::cout << "START CORE LOOP" <<std::endl;

    while(clients.size() > 0 && animals.size() > 0){
        if(FLAG_PRINT_DEBUG){
            for(uint i = 0; i < clients.size(); i++){
                std::cout << "CLIENT "<< i << " - "<< clients.at(i).getFirstName().toStdString() <<std::endl;
                for(uint j = 0; j < animals.size(); j++){
                    float compatability = compatArray.at(i).at(j);
                    std::cout << "  "<< compatability;
                }
                std::cout << std::endl;
            }

            std::cout << "begin >> " << std::endl;
            std::cout << "FIND_MIN_START" << std::endl;
        }

        // GET INDEX OF CLIENT WITH MIN MATCHES /
        int minClientIndex = 0;
        for(uint i = 0; i < compatArray.size(); i++){
            if(nMatchs.at(i) < nMatchs.at(minClientIndex)){
                minClientIndex = i;
            }
        }

        if(FLAG_PRINT_DEBUG)
            std::cout << "FIND_MIN_END" << std::endl;
        if(FLAG_PRINT_DEBUG)
            std::cout << "FIND_MATCHES_START" << std::endl;
        //TODO OPTIMIZE
        if (nMatchs.at(minClientIndex) != 0){   //IF CLIENT HAS MATCHES
            int minAnimalIndex = -1;
            for(uint i = 0; i < compatArray.at(minClientIndex).size(); i++){
                if(compatArray.at(minClientIndex).at(i) != 0){  //ANIMAL FOUND, BREAK AND ADD
                    minAnimalIndex = i;
                    break;
                }
            }

            //create result and add to return vector
            resultVec.push_back(std::make_pair(clients.at(minClientIndex), animals.at(minAnimalIndex)));

            //remove animal from vectors
            animals.erase(animals.begin() + minAnimalIndex);
            for(uint i = 0; i < compatArray.size(); i++){
                compatArray.at(i).erase(compatArray.at(i).begin() + minAnimalIndex);
            }

        }else{
            //IF CLIENT HAS NO MATCHES, DO NOTHING
        }
        if(FLAG_PRINT_DEBUG)
            std::cout << "FIND_MATCHES_END" << std::endl;

        if(FLAG_PRINT_DEBUG)
            std::cout << "REMOVE_CLIENT_START" << std::endl;
        //REMOVE CLIENT FROM MATCHING POOL
        nMatchs.erase(nMatchs.begin() + minClientIndex);
        clients.erase(clients.begin() + minClientIndex);
        compatArray.erase(compatArray.begin() + minClientIndex);

        if(FLAG_PRINT_DEBUG)
            std::cout << "REMOVE_CLIENT_END" << std::endl;
    }


    //*/
    if(FLAG_PRINT_END_MATCHES){
        std::cout << "ACM ENDED" <<std::endl;
        std::cout << "DISPLAYING MATCHES" << std::endl;
        for(uint i = 0; i < resultVec.size(); i++){
            std::pair<Client, Animal> match = resultVec.at(i);
            std::cout << match.first.getFirstName().toStdString() << " with " << match.second.getName().toStdString() << " - "<< 100.0f*getCompatabilityIndex(match.second, match.first) << "% match"<< std::endl;
        }
    }
    return resultVec;


}

void ACM::printCLIENT(Client C){
    using namespace std;

    cout << "CLIENT NAME: " << C.getFirstName().toStdString() << " " << C.getLastName().toStdString() << endl;
    cout << "  CHILD FRIENDLY:    " << C.getChildFriendly() << " (1 = yes | 3 = no | 2 = don't care)" << endl;
    cout << "  STRANGER FRIENDLY: " << C.getStrangerFriendly() << " (1 = yes | 3 = no | 2 = don't care)" << endl;
    cout << "  Behaviour     - " << C.getBehaviour() << "/10 - rank "<< C.getBehaveRank() << endl;
    cout << "  Owner Control - " << C.getOwnerControl() << "/10 - rank "<< C.getOwnerRank() << endl;
    cout << "  Sociability   - " << C.getSociability() << "/10 - rank "<< C.getSocialRank() << endl;
    cout << endl;

}

void ACM::printANIMAL(Animal A){
    using namespace std;

    cout << "ANIMAL NAME: " << A.getName().toStdString() << endl;
    cout << "  CHILD FRIENDLY:    " << A.getChildFriendly() << " (1,2 = no | 3,4,5 = yes)" << endl;
    cout << "  STRANGER FRIENDLY: " << A.getStrangerFriendly() << " (1,2 = no | 3,4,5 = yes)" << endl;

    cout << "  Behaviour" << endl;
    cout << "    Patience:       " << A.getPatience() << "/10" << endl;
    cout << "    Temperament:    " << A.getTemperament() << "/5" << endl;
    cout << "    Michievousness: " << A.getMischievousness() << "/10" << endl;

    cout << "  Owner Control" << endl;
    cout << "    Training Ease:         " << A.getTrainability() << "/5" << endl;
    cout << "    Training Intelligence: " << A.getIntelligence() << "/10" << endl;
    cout << "    Obedience:             " << A.getObedience() << "/10" << endl;

    cout << "  Sociability" << endl;    //done
    cout << "    Playfullness:       " << A.getPlayfulness() << "/10" << endl;
    cout << "    Energy:             " << A.getEnergy() << "/5" << endl;
    cout << "    Independence:       " << A.getIndependence() << "/10" << endl;
    cout << "    Animal Sociability: " << A.getSocialAttitutde() << "/10" << endl;
    cout << endl;
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

    if(C.getStrangerFriendly() != 2 && C.getStrangerFriendly() == animalStrangerPref)
    {return overallCIX = 0;}

    if(C.getChildFriendly() != 2 && C.getChildFriendly() == animalChildPref)
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
    /*if(C.getOwnerRank() == C.getBehaveRank() && C.getOwnerRank() == C.getSocialRank()){
        if(C.getOwnerRank() == 4){ //Handles scenario if all ranks are no preferences
            return overallCIX = 1;
        }
    }*/

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
