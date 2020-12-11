#include <iostream>

const static int SIMULATION_DAYS = 90;

/* the probability of transfering from susceptible to presymptomatic 
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;

/* It may take 1 ~ 14 days to show symtoms */
const static float PRESYMPTOMATIC_TO_MILD = 0.25;
const static float ASYMPTOMATIC_TO_RECOVERED = 0.3;

const static float MILD_TO_SEVERE = 0.3;
const static float MILD_TO_RECOVERED = 0.3;

const static float SEVERE_TO_RECOVERED = 0.3;
const static float SEVERE_TO_DEAD = 0.03;

/* a global clock */
static int days = 0;

int main() {

    /* initialize the network */

    /* initialize the agents */


    for ( ; days < SIMULATION_DAYS; days++ ) {
        /* generate an event for each agent for today */
        /* each agent has only one event each day */

        // TODO

        /* Every agent executes the event in parallel */

        /* barrier */

        /* Every agent updates the state in parallel */


        /* statistics */
        
    }

}
