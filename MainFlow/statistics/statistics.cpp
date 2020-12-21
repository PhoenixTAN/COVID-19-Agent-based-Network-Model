
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

    NUM_OF_SUSCEPTIBLE = 0;
    NUM_OF_PRESYMPTOMATIC = 0;
    NUM_OF_ASYMPTOMATIC = 0;
    NUM_OF_MILD = 0;
    NUM_OF_SEVERE = 0;
    NUM_OF_RECOVERED = 0;
    NUM_OF_DEATH = 0;

    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        WELLNESS state = agent->getWellness();

        switch (state) {
            case SUSCEPTIBLE:
                NUM_OF_SUSCEPTIBLE++;
                break;
            case PRESYMPTOMATIC:
                NUM_OF_PRESYMPTOMATIC++;
                break;
            case ASYMPTOMATIC:
                NUM_OF_ASYMPTOMATIC++;
                break;
            case MILD:
                NUM_OF_MILD++;
                break;
            case SEVERE:
                NUM_OF_SEVERE++;
                break;
            case RECOVERED:
                NUM_OF_RECOVERED++;
                break;
            case DEAD:
                NUM_OF_DEATH++;
                break;
            default:
                break;
        }
    }

    /* print the statistics to txt file */
    file << NUM_OF_SUSCEPTIBLE << " " 
            << NUM_OF_PRESYMPTOMATIC << " "
            << NUM_OF_ASYMPTOMATIC << " "
            << NUM_OF_MILD << " "
            << NUM_OF_SEVERE << " "
            << NUM_OF_RECOVERED << " "
            << NUM_OF_DEATH << " "
    << std::endl;

    file.close();
    
}
