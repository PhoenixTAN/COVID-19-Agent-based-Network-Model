
#include  "../agent/hpp/agent.hpp"
#include "../params.hpp"

#include <fstream>  /* file stream */
#include <iostream>


/**
 * @Author print state in terminal and file system
 * 
*/
void printAgentState(Agent* network, int NETWORK_SIZE) {

    std::ofstream file;

    file.open("./statistics/statistics.txt", std::ofstream::out | std::ofstream::app);

    if ( file.bad() ) {
        std::cout << "cannot open file" << std::endl;
    }

    
    numOfSusceptible = 0;
    numOfPresymptomatic = 0;
    numOfAsymptomatic = 0;
    numOfMild = 0;
    numOfRecovered = 0;
    numOfSevere = 0;
    numOfDead = 0;

    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        WELLNESS state = agent->getWellness();

        switch (state) {
            case SUSCEPTIBLE:
                numOfSusceptible++;
                break;
            case PRESYMPTOMATIC:
                numOfPresymptomatic++;
                break;
            case ASYMPTOMATIC:
                numOfAsymptomatic++;
                break;
            case MILD:
                numOfMild++;
                break;
            case SEVERE:
                numOfSevere++;
                break;
            case RECOVERED:
                numOfRecovered++;
                break;
            case DEAD:
                numOfDead++;
                break;
            default:
                break;
        }
    }

    /* print the statistics to txt file */
    file << numOfSusceptible << " " 
            << numOfPresymptomatic << " "
            << numOfAsymptomatic << " "
            << numOfMild << " "
            << numOfSevere << " "
            << numOfRecovered << " "
            << numOfDead << " "
    << std::endl;

    file.close();
    
}
