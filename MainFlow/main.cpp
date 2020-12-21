#include <iostream>
#include <ctime>    /* time seed */
#include <omp.h>    /* OpenMP */
#include "params.hpp"
#include "agent/hpp/agent.hpp"
#include "event/hpp/event.hpp"
#include "init/hpp/init.hpp"
#include "time/hpp/clock.hpp"
#include "time/hpp/hour.hpp"
#include "statistics/statistics.hpp"
#include "event_generator/event_generator.hpp"

/* create the network */
Agent* network = new Agent[NETWORK_SIZE];


/**
 * @Author Ziqi Tan
 * @Description execute the events
*/
void agentEventExecution(Agent* network, int NETWORK_SIZE) {

    // execute the events in each agent in parallel
    #pragma omp parallel for num_threads(MAX_NUM_OF_THREADS)
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        agent->executeEvent();
    }

}

void updateAgentState(Agent* network, int NETWORK_SIZE) {

    #pragma omp parallel for num_threads(MAX_NUM_OF_THREADS)
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        Agent* agent = &network[i];
        agent->updateWellness();
    }
}



int main() {

    /* Initialize the clock */
    Clock* clock = Clock::getInstance();

    /* set agent id */
    init_agents(network, NETWORK_SIZE, INITIAL_NUM_OF_PRESYMTOMATIC);

    /* initialize the network */
    std::cout << "initializing the network..." << std::endl;
    init_network(network, NETWORK_SIZE);

    /* print network */
    // print_network(network, NETWORK_SIZE);

    std::cout<<"Setting up random seed: " << RANDOM_SEED << std::endl;
    srand(RANDOM_SEED);

    /* OpenMP */
    std::cout << "Using OpenMP library for parallel computing. Max thread: " << MAX_NUM_OF_THREADS << std::endl;

    /* Event generator */
    EventGenerator* eventGenerator = EventGenerator::getInstance();

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
        int intervention_level = 0;
        switch (hour)
        {
            case WORKING:
                /* generate an event for each agent for each hour */
                /* each agent has only one event each hour */
                /* initialize meeting events based on social network */

                
                if ( numOfDead / (float)NETWORK_SIZE > THRESHOLD3_OF_DEATH ) {
                    intervention_level = 5;
                }
                else if ( numOfDead > THRESHOLD2_OF_DEATH ) {
                    intervention_level = 4;
                }
                else if ( numOfDead > THRESHOLD_OF_DEATH ) {
                    intervention_level = 3;
                }
                else if ( numOfMild + numOfSevere > THRESHOLD2_OF_MILD_SEVERE ) {
                    intervention_level = 2;
                }
                else if ( numOfMild + numOfSevere > THRESHOLD_OF_MILD_SEVERE ) {
                    intervention_level = 1;
                }


                for ( int i = 0; i < NUM_OF_MEETING_EACH_HOUR * FACTOR_OF_EVENTS[intervention_level]; i++ ) {
                    eventGenerator->createMeetingEvents(network);
                }

                /* initialize social interaction events*/
                for ( int i = 0; i < NUM_OF_SOCIAL_EACH_HOUR * FACTOR_OF_EVENTS[intervention_level]; i++ ) {
                    eventGenerator->createSocialInterationEvents(network);
                }
                
                /* Every agent executes the event in parallel */
                agentEventExecution(network, NETWORK_SIZE);
                /* barrier */

                break;
            
            case SLEEPING:
                // sleeping time, do nothing
                break;

            default:
                break;
        }

        /* Every agent updates the state in parallel */
        updateAgentState(network, NETWORK_SIZE);
        /* barrier */

        /* go on to the next hour */
        clock->nextHour();

        /* statistics for each day */
        if (hourNum == 23) {
            std::cout << "Day " << day << std::endl;
            printAgentState(network, NETWORK_SIZE);
        }
        
    }

}
