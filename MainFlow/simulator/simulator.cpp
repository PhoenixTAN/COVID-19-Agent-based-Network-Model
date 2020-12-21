#include "simulator.hpp"
#include <iostream>
#include "../statistics/statistics.hpp"
#include "../params.hpp"
#include <omp.h>    /* OpenMP */

Clock* Simulator::clock = NULL;
Agent* Simulator::network = NULL;
EventGenerator* Simulator::eventGenerator = NULL;


Simulator::Simulator(Clock* clock, Agent* network, EventGenerator* eventGenerator) {
    Simulator::clock = clock;
    Simulator::network = network;
    Simulator::eventGenerator = eventGenerator;
}

void Simulator::start() {
    std::cout << "Initializing agents..." << std::endl;
    /* set agent id */
    init_agents();

    /* initialize the network */
    init_network();

    /* print network */
    print_network();

    int intervention_level = 0;
    // while loop for every hour
    while(true){

        HOUR hour = clock->getCurrentHour();
        int day = clock->getCurrentDay();
        int hourNum = clock->getCurrentHourNum();

        if ( day == -1 ) {
            // simulation ends
            break;
        }

        // create a hash set for Agents' id

        eventGenerator->createAgentSet(network);
        
        switch (hour)
        {
            case WORKING:
                /* generate an event for each agent for each hour */
                /* each agent has only one event each hour */
                /* initialize meeting events based on social network */

                for ( int i = 0; i < NUM_OF_MEETING_EACH_HOUR * FACTOR_OF_EVENTS[intervention_level]; i++ ) {
                    eventGenerator->createMeetingEvents(network);
                }

                /* initialize social interaction events*/
                for ( int i = 0; i < NUM_OF_SOCIAL_EACH_HOUR * FACTOR_OF_EVENTS[intervention_level]; i++ ) {
                    eventGenerator->createSocialInterationEvents(network);
                }
                
                /* Every agent executes the event in parallel */
                agentEventExecution();
                /* barrier */

                break;
            
            case SLEEPING:
                // sleeping time, do nothing
                break;

            default:
                break;
        }

        /* Every agent updates the state each hour in parallel */
        updateAgentState();
        /* barrier */

        /* go on to the next hour */
        clock->nextHour();

        /* statistics for each day */
        if (hourNum == 23) {
            std::cout << "Day " << day  << " ends."<< std::endl;
            printAgentState(network, NETWORK_SIZE);

            if ( NUM_OF_DEATH / (float)NETWORK_SIZE > THRESHOLD3_OF_DEATH ) {
                intervention_level = 5;
            }
            else if ( NUM_OF_DEATH > THRESHOLD2_OF_DEATH ) {
                intervention_level = 4;
            }
            else if ( NUM_OF_DEATH > THRESHOLD_OF_DEATH ) {
                intervention_level = 3;
            }
            else if ( NUM_OF_MILD + NUM_OF_SEVERE > THRESHOLD2_OF_MILD_SEVERE ) {
                intervention_level = 2;
            }
            else if ( NUM_OF_MILD + NUM_OF_SEVERE > THRESHOLD_OF_MILD_SEVERE ) {
                intervention_level = 1;
            }

            if ( intervention_level != 0 ) {
                std::cout << "Intervention level: " << intervention_level << std::endl;
            }
        }
        
    }

    std::cout << "Simulation ends." << std::endl;
}

/**
 * @Author Ziqi Tan
 * @Description set agent id and randomly infect some people.
*/
void Simulator::init_agents() {

    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        network[i].setId(i);
    }

    /* randomly infect some people */
    std::cout << "Randomly infect " << INITIAL_NUM_OF_PRESYMTOMATIC << " people." << std::endl; 
    int infected = 0;
    while ( infected < INITIAL_NUM_OF_PRESYMTOMATIC) {
        int agentID = rand() % NETWORK_SIZE;
        network[agentID].setWellness(PRESYMPTOMATIC);
        network[agentID].setIncubationPeriod(true);     // true: default incubation period
        infected++;
    }
}

/**
 * Description: use BA algorithm to initialize social network.
 * 
*/
void Simulator::init_network() {

    std::cout << "Initializing the network: " << std::endl;
    /* initial network size */
    int initialSize = 10;
    
    /* connect others with half and half probability */
    const float PROBABILITY_OF_CONNECTION = 0.5;

    /* initialize part of the network */
    for ( int i = 0; i < initialSize && i < NETWORK_SIZE; i++ ) {
        
        for ( int j = 0; j < initialSize && j < NETWORK_SIZE; j++ ) {
            // a node cannot connect itself
            if ( i == j ) {
                continue;
            }

            // flip coin
            float coin = rand() / (float)(RAND_MAX);

            if ( coin < PROBABILITY_OF_CONNECTION && !network[i].hasNeighbor(network[j].getId()) ) {
                network[i].addNeighbor(j);
                network[j].addNeighbor(i);
            }
        }
    }

    /* initialize the whole network */
    /* add new nodes to the initial network */
    for ( int i = initialSize; i < NETWORK_SIZE; i++ ) {
        if ( i % 1000 == 0 ) {
            std::cout <<  i / (float)NETWORK_SIZE * 100.0 << "% " << "\r";
        }
        for ( int j = 0; j < i; j++ ) {
            /* the probability of that agent i join agent j's network */
            /* avoid dividing zero and one */
            float probabilityToJoin = 1.0 / (network[j].getNumOfNeighbors() * 50 + 2);
            float coin = rand() / (float)(RAND_MAX);

            if ( coin < probabilityToJoin ) {
                network[i].addNeighbor(j);
                network[j].addNeighbor(i);
            }
        }
    }

    std::cout << "Finish!" << std::endl;
}


/**
 * @Author Ziqi Tan
 * @Description print the social network
 *
*/
void Simulator::print_network() {
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        std::cout << "Agent " << i << ": ";
        std::bitset<NETWORK_SIZE>* neighbors = network[i].getNeighbors();
        std::cout << "num of neighbors: " << network[i].getNumOfNeighbors() <<  "     ";
        /*for ( int j = 0; j < neighbors->size(); j++ ) {
            if ( neighbors->test(j) ) {
                std::cout << j << " ";
            }
        }*/
        std::cout << std::endl;
    }
}

/**
 * @Author Ziqi Tan
 * @Description execute the events
*/
void Simulator::agentEventExecution() {

    // execute the events in each agent in parallel
    #pragma omp parallel for num_threads(MAX_NUM_OF_THREADS)
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        agent->executeEvent();
    }

}

void Simulator::updateAgentState() {

    #pragma omp parallel for num_threads(MAX_NUM_OF_THREADS)
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        agent->updateWellness();
    }
}