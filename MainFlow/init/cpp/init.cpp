#include "../hpp/init.hpp"
#include <cstdlib>      /* random number */
#include <time.h>
#include <iostream>
#include <algorithm>    // std::max


/**
 * Description: use 
 * 
*/
void init_network(Agent* network, int NETWORK_SIZE) {
    /* initial network size */
    // const int INITIAL_NETWORK_PROPORTION = 10;

    // int initialSize = NETWORK_SIZE / INITIAL_NETWORK_PROPORTION;
    int initialSize = 10;
    /* connect others with half and half probability */
    const float PROBABILITY_OF_CONNECTION = 0.5;

    /* initialize part of the network */
    for ( int i = 0; i < initialSize && i < NETWORK_SIZE; i++ ) {
        if ( i % 50 == 0 ) {
            std::cout << "Initializing agent " << i << std::endl;
        }
        
        for ( int j = 0; j < initialSize && i < NETWORK_SIZE; j++ ) {
            // a node cannot connect itself
            if ( i == j ) {
                continue;
            }

            // flip coin
            float coin = rand() / (float)(RAND_MAX);

            if ( coin < PROBABILITY_OF_CONNECTION && !network[i].hasNeighbor(network[j].getId()) ) {
                network[i].addNeighbor(&network[j]);
                network[j].addNeighbor(&network[i]);
            }
        }
    }

    /* initialize the whole network */
    /* add new nodes to the initial network */
    for ( int i = initialSize; i < NETWORK_SIZE; i++ ) {
        if ( i % 50 == 0 ) {
            std::cout << "Initializing agent " << i << std::endl;
        }
        for ( int j = 0; j < i; j++ ) {
            /* the probability of that agent i join agent j's network */
            /* avoid dividing zero and one */
            float probabilityToJoin = 1.0 / (network[j].getNeighbors().size() + 2);
            float coin = rand() / (float)(RAND_MAX);

            if ( coin < probabilityToJoin /*&& !network[i].hasNeighbor(network[j].getId())*/ ) {
                network[i].addNeighbor(&network[j]);
                network[j].addNeighbor(&network[i]);
            }
        }
    }
}

void init_agents(Agent* network, int NETWORK_SIZE, int INITIAL_NUM_OF_PRESYMTOMATIC) {
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        network[i].setId(i);
    }

    /* randomly infect some people */
    int infected = 0;
    while ( infected < INITIAL_NUM_OF_PRESYMTOMATIC) {
        int agentID = rand() % NETWORK_SIZE;
        network[agentID].setWellness(PRESYMPTOMATIC);
        network[agentID].setIncubationPeriod(true);     // true: default incubation period
        infected++;
    }
}

