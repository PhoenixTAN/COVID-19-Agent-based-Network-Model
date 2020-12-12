#include "../hpp/init.hpp"
#include <cstdlib>      /* random number */
#include <time.h>
#include <iostream>
#include "../../params.hpp"


/**
 * Description: use 
 * 
*/
void init_network(Agent* network, int NETWORK_SIZE) {
    // initial network size
    int initialSize = NETWORK_SIZE / 10;
    srand(RANDOM_SEED);

    // connect others with half and half probability
    float PROBABILITY_OF_CONNECTION = 0.6;

    // initialize part of the network
    for ( int i = 0; i < initialSize; i++ ) {
        for ( int j = 0; j < initialSize; j++ ) {
            if ( i == j ) {
                // a node cannot connect itself
                continue;
            }

            // flip coin
            float coin = rand() / (float)(RAND_MAX);

            if ( coin < PROBABILITY_OF_CONNECTION ) {
                network[i].addNeighbor(&network[j]);
                network[j].addNeighbor(&network[i]);
            }
        }
    }

    // initialize the whole network
    // add new nodes the initial network
    for ( int i = initialSize; i < NETWORK_SIZE; i++ ) {
        for ( int j = 0; j < NETWORK_SIZE; j++ ) {
            if ( i == j ) {
                // a node cannot connect itself
                continue;
            }

            /* the probability of that agent i join agent j's network */
            /* avoid dividing zero */
            float probabilityToJoin = 1.0 / (network[j].getNeighbors().size() + 1);
            float coin = rand() / float(RAND_MAX);

            if ( coin < probabilityToJoin ) {
                network[i].addNeighbor(&network[j]);
                network[j].addNeighbor(&network[i]);
            }
        }
    }
}

void init_agents(Agent* network, int NETWORK_SIZE) {
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        network[i].setId(i);
    }
}

void init_event(){
    
}
