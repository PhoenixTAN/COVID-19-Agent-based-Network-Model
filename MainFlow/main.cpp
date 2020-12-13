#include <iostream>
#include <set>
#include "params.hpp"
#include "agent/hpp/agent.hpp"
#include "event/hpp/event.hpp"
#include "init/hpp/init.hpp"
#include "time/hpp/clock.hpp"
#include "time/hpp/hour.hpp"
#include "event/hpp/meeting.hpp"
#include "event/hpp/non_transmission_event.hpp"
#include "event/hpp/transmission_event.hpp"
#include "event/hpp/social_activity.hpp"
#include "event/hpp/stay_alone.hpp"


void createAgentSet(std::set<int> &set, Agent* network){
    for(int i = 0; i < NETWORK_SIZE; i++){
        set.insert(network[i].getId());
    }
}

void createSocialInterationEvents(std::set<int> &set, Agent* network) {
    std::cout << "Creating social interaction events" << std::endl;

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

void createMeetingEvents(std::set<int> &set, Agent* network){

    std::cout << "creating meeting events" << std::endl;

    // initialize an event
    Event* event = new Meeting();

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

    // get his neighbors
    std::vector<Agent*> neighbors = agent.getNeighbors();

    // set event to this agent
    agent.setEvent(event);
    // add condition of agent to this event
    event->increment(agent.getWellness());
    // delete the agent in set
    set.erase(agentID);

    for(int i = 0; i < neighbors.size(); i++){
        Agent* neighbor = neighbors[i];
        if(network[agentID].getWellness() != DEAD){
            neighbor->setEvent(event);
        }
        event->increment(neighbor->getWellness());
        set.erase(neighbor->getId());
    }

}

void print_network(Agent* network, int NETWORK_SIZE) {
    for ( int i = 0; i < NETWORK_SIZE; i++ ) {
        std::cout << "Agent " << i << ": ";
        std::vector<Agent*> neighbors = network[i].getNeighbors();
        for ( int j = 0; j < neighbors.size(); j++ ) {
            std::cout << neighbors[j]->getId() << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    /* Initialize the clock */
    Clock* clock = Clock::getInstance();

    /* create the network */
    Agent* network = new Agent[NETWORK_SIZE];

    /* set agent id */
    std::cout << "set agent id" << std::endl;
    init_agents(network, NETWORK_SIZE);

    /* initialize the network */
    std::cout << "initialize the network..." << std::endl;
    init_network(network, NETWORK_SIZE);

    /* print network */
    print_network(network, NETWORK_SIZE);
    
    /* initialize the whole network, set neighbors */
    init_network(network, NETWORK_SIZE);

    srand(RANDOM_SEED);

    // create a hash set for Agents' id
    
    std::set<int> agentSet;
    createAgentSet(agentSet, network);

    for(int id:agentSet){
        std::cout << id << std::endl;
    }
    
    // while loop for every hour
    while(true){

        HOUR hour = clock->getCurrentHour();
        int day = clock->getCurrentDay();
        int hourNum = clock->getCurrentHourNum();

        std::cout << "day " << day << "   hour " << hourNum << std::endl;

        if ( day == -1 ) {
            // simulation ends
            break;
        }

        switch (hour)
        {
            case WORKING:
            {

                /* generate an event for each agent for each hour */
                /* each agent has only one event each day */

                /* initialize meeting events based on social network*/
                createMeetingEvents(agentSet, network);


                /* initialize social interaction events*/
                // createSocialInterationEvents(agentSet, network);

                /* Every agent executes the event in parallel */

                // TODO

                /* barrier */

                /* Every agent updates the state in parallel */

                /* barrier */

                break;
            }
            case SLEEPING:
                // sleeping time, do nothing
                std::cout << "Sleeping" << std::endl;
                break;

            default:
                break;
        }

        clock->nextHour();

        /* statistics for each day */
    }


}
