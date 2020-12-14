#ifndef PARAMS_H
#define PARAMS_H

#include <algorithm>    // std::max
#include <random>

extern std::default_random_engine DEFAULT_RANDOM_ENGINE;

const static unsigned int RANDOM_SEED = 10;

const static int SIMULATION_DAYS = 30;
const static int NETWORK_SIZE = 100;

const static int MAXIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR = 5;
const static int MINIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR = 2;
const static float EXECUTE_SOCIAL_EVENT = 0.5;
const static float EXECUTE_METTING_EVENT = 0.7;

static int INITIAL_NUM_OF_PRESYMTOMATIC = std::max(5, NETWORK_SIZE / 1000);


/* the probability of transfering from susceptible to presymptomatic 
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;
const static float INFECTIOUS_TO_ASYMPTOMATIC = 0.2;

/* It may take 1 ~ 14 days to show symtoms */
const static float PRESYMPTOMATIC_TO_MILD = 0.25;
const static int INCUBATION_PEROID = 14;        // days
const static int INCUBATION_EXPECTATION = 7;    // days
const static int INCUBATION_VARIANCE = 3;       // days


const static int ASYMPTOMATIC_PERIOD = 5;       // days
const static int MIN_ASYMPTOMATIC_PEROID = 4;

/* after this period, agent will have a high probability to get severe */
const static int MILD_PERIOD = 3;       // days
const static int MIN_MILD_PERIOD = 2;   // days
const static float MILD_TO_SEVERE = 0.6;

/* after this period, agent will have a high period to die */
const static int SEVERE_PERIOD = 3;     // days
const static int MIN_SEVERE_PERIOD = 2;   // days

const static float SEVERE_TO_RECOVERED = 0.6;
const static float SEVERE_TO_DEAD = 0.03;

// P{ i get infect when agent j state is mild} = a
const static float INFECTION_RATE_MILD = 0.4;
// P{ i get infect when agent j state is severe} = b
const static float INFECTION_RATE_SEVERE = 0.6;
// P{ i get infect when agent j state is presymptomatic} = c
const static float INFECTION_RATE_PRESYMPTOMATIC = 0.3;
// P{ i get infect when agent j state is asymptomatic} = d
const static float INFECTION_RATE_ASYMPTOMATIC = 0.2;

#endif