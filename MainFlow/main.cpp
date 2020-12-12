#include <iostream>
#include "params.hpp"
#include "Agent/hpp/Agent.hpp"
#include "Event/hpp/Meeting.hpp"
#include "init/hpp/init.hpp"


/* a global clock */
static int days = 0;

int main() {

    /* initialize the network */
    Agent* network = new Agent[NETWORK_SIZE];
    init_network(network, NETWORK_SIZE);

    /* initialize the agents */
    Agent* agent = new Agent(0);
    agent->setEvent(new Meeting());
    
    /* initialize the events */


    for ( ; days < SIMULATION_DAYS; days++ ) {
        /* generate an event for each agent for today */
        
        /* each agent has only one event each day */

        // TODO

        /* Every agent executes the event in parallel */

        /* barrier */

        /* Every agent updates the state in parallel */

        /* barrier */

        /* statistics */

    }

}
