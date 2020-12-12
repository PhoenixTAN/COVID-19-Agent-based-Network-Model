#include <iostream>
#include <set>
#include "params.hpp"
#include "agent/hpp/agent.hpp"
#include "event/hpp/event.hpp"
#include "init/hpp/init.hpp"
#include "time/hpp/clock.hpp"
#include "event/hpp/meeting.hpp"
#include "event/hpp/non_transmission_event.hpp"
#include "event/hpp/transmission_event.hpp"
#include "event/hpp/social_activity.hpp"
#include "event/hpp/stay_alone.hpp"


void createAgentSet(std::set<int> set, Agent* network){
    for(int i = 0; i < NETWORK_SIZE; i++){
        set.insert(network[i].getId());
    }
}

void createSocialInterationEvents(std::set<int> set, Agent* network){

    int numberOfEvent = rand() % (MAXIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR - 1) + 1; // the number of social events

    for(int i = 0; i < numberOfEvent; i++){

        if(set.size() < MINIMUM_AGENT_IN_SOCIAL_EVENT){
            break;
        }

        // initialize an event
        Event* event = new SocialActivity();

        // the number of agents who will execute this event
        int numberOfAgents = rand() % (set.size() - MINIMUM_AGENT_IN_SOCIAL_EVENT) + MINIMUM_AGENT_IN_SOCIAL_EVENT; 

        // assgin social event for every agents who will execute this event
        for(int j = 0; j < numberOfAgents; j++){

            int agentID = rand() % NETWORK_SIZE;

            // ensure random agent has no event 
            while(true){
                auto search = set.find(agentID);
                if(search != set.end() && network[agentID].getWellness() != DEAD) {
                    break;
                }
                agentID = rand() % NETWORK_SIZE;
            }

            Agent agent = network[agentID];
            // set event to this agent
            agent.setEvent(event);
            // add condition of agent to this event
            event->increment(agent.getWellness());
            // delete the agent in set
            set.erase(agentID);
        }
    }
}

void createMeetingEvents(std::set<int> set, Agent* network){

    int numberOfEvent = rand(); // the number of social events

    int numberOfAgents = rand();  // the number of agents who will execute this event

    int numberOfEvent = rand() % (MAXIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR - 1) + 1; // the number of social events

    for(int i = 0; i < numberOfEvent; i++){

        if(set.size() < MINIMUM_AGENT_IN_SOCIAL_EVENT){
            break;
        }

        // initialize an event
        Event* event = new SocialActivity();

        // the number of agents who will execute this event
        int numberOfAgents = rand() % (set.size() - MINIMUM_AGENT_IN_SOCIAL_EVENT) + MINIMUM_AGENT_IN_SOCIAL_EVENT; 

        // assgin social event for every agents who will execute this event
        for(int j = 0; j < numberOfAgents; j++){

            int agentID = rand() % NETWORK_SIZE;

            // ensure random agent has no event 
            while(true){
                auto search = set.find(agentID);
                if(search != set.end() && network[agentID].getWellness() != DEAD) {
                    break;
                }
                agentID = rand() % NETWORK_SIZE;
            }

            Agent agent = network[agentID];

            // set event to this agent
            agent.setEvent(event);
            // add condition of agent to this event
            event->increment(agent.getWellness());
            // delete the agent in set
            set.erase(agentID);
        }
    }

}

int main() {

    /* Initialize the clock */
    Clock* clock = Clock::getInstance();

    /* initialize the network */
    Agent* network = new Agent[NETWORK_SIZE];
    init_network(network, NETWORK_SIZE);

    /* initialize the agents */
    Agent* agent = new Agent(0);

    srand(RANDOM_SEED);
    
    // while loop for every hour
    while(true){

        HOUR hour = clock->getCurrentHour();
        int day = clock->getCurrentDay();

        if(day == -1){
            // simulation ends
            break;
        }

        switch (hour)
        {
            case WORKING:
            {
                // create a hash set for Agents' id

                std::set<int> agentSet;
                createAgentSet(agentSet, network);

                /* generate an event for each agent for each hour */
                /* each agent has only one event each day */

                /* initialize social interaction events*/

                createSocialInterationEvents(agentSet, network);

                /* initialize meeting events based on social network*/

                createMeetingEvents(agentSet, network);

                /* Every agent executes the event in parallel */

                // TODO

                /* barrier */

                /* Every agent updates the state in parallel */

                /* barrier */

                break;
            }
            case SLEEPING:
                // sleeping time, do nothing
                break;

            default:
                break;
        }

        clock->nextHour();

        /* statistics for each day */
    }


    /* statistics */


}
