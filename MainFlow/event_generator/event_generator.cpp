#include "event_generator.hpp"
#include "../event/hpp/meeting.hpp"
#include "../event/hpp/non_transmission_event.hpp"
#include "../event/hpp/transmission_event.hpp"
#include "../event/hpp/social_activity.hpp"
#include "../event/hpp/stay_alone.hpp"
#include <set>

EventGenerator* EventGenerator::instance = NULL;
std::set<int> EventGenerator::agentSet;

EventGenerator::EventGenerator() {}

EventGenerator* EventGenerator::getInstance() {
    if ( EventGenerator::instance == NULL ) {
        EventGenerator::instance = new EventGenerator();
    }
    return EventGenerator::instance;
}

/**
 * @Author Xueyan Xia
 * @Description The set contains the agents who currently have no event
*/
void EventGenerator::createAgentSet(Agent* network){
    
    EventGenerator::agentSet.clear();

    for(int i = 0; i < NETWORK_SIZE; i++){
        EventGenerator::agentSet.insert(network[i].getId());
    }
}

void EventGenerator::createSocialInterationEvents(Agent* network) {

    if(EventGenerator::agentSet.empty()){
        return;
    }

    // the number of agents who will execute this event
    int numberOfAgents = rand() % (MAXIMUM_NUM_OF_AGENTS_EACH_SOCIAL_EVENT -  MINIMUM_NUM_OF_AGENTS_SOCIAL_EVENT) + MINIMUM_NUM_OF_AGENTS_SOCIAL_EVENT;

    if(EventGenerator::agentSet.size() < numberOfAgents){
        return;
    }

    // initialize an event
    Event* event = new SocialActivity();

    int count = 0;

    // assgin social event for every agents who will execute this event
    for(int i = 0; i < NETWORK_SIZE; i++){

        Agent* agent = &network[i];

        // ensure random agent has no event
        auto search = EventGenerator::agentSet.find(agent->getId());
        if(search != EventGenerator::agentSet.end() && agent->getWellness() != DEAD && agent->getEvent() == NULL) {

            // Probability
            float probability = rand() / float(RAND_MAX);

            if(probability < EXECUTE_SOCIAL_EVENT){
                // set event to this agent
                agent->setEvent(event);
                // add condition of agent to this event
                event->increment(agent->getWellness());
                // delete the agent in set
                EventGenerator::agentSet.erase(agent->getId());
            }else{
                event = new StayAlone();
                agent->setEvent(event);
                EventGenerator::agentSet.erase(agent->getId());
            }

            count++;

            if(count == numberOfAgents){
                break;
            }
        }
    }
}


/**
 * @Author Xueyan Xia
 * @Description: create a meeting events for an angent and inform his/her neighbors
 *
*/
void EventGenerator::createMeetingEvents(Agent* network) {

    // initialize an event
    Event* event = new Meeting();

    int agentID = rand() % NETWORK_SIZE;
    
    // ensure random agent has no event 
    while(true){
        auto search = EventGenerator::agentSet.find(agentID);
        // if a not dead agent has no event currently
        if(search != EventGenerator::agentSet.end() && network[agentID].getWellness() != DEAD) {
            break;
        }
        agentID = rand() % NETWORK_SIZE;
    }


    Agent* agent = &network[agentID];

    // get his neighbors
    std::vector<Agent*> neighbors = agent->getNeighbors();

    // set event to this agent
    agent->setEvent(event);
    // add condition of agent to this event
    event->increment(agent->getWellness());
    // delete the agent in set
    EventGenerator::agentSet.erase(agentID);

    for(int i = 0; i < neighbors.size(); i++){
        
        Agent* neighbor = neighbors[i];

        auto search = EventGenerator::agentSet.find(neighbor->getId());
        if(network[agentID].getWellness() != DEAD && search != EventGenerator::agentSet.end()){

            // Probability
            float probability = rand() / float(RAND_MAX);

            if(probability < EXECUTE_METTING_EVENT){
                neighbor->setEvent(event);
                event->increment(neighbor->getWellness());
                EventGenerator::agentSet.erase(neighbor->getId());
            } else {
                event = new StayAlone();
                neighbor->setEvent(event);
                EventGenerator::agentSet.erase(neighbor->getId());
            }

        }
    }

}

