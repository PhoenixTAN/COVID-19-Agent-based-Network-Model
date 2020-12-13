#ifndef PARAMS_H
#define PARAMS_H

const static unsigned int RANDOM_SEED = 1;

const static int SIMULATION_DAYS = 3;
const static int NETWORK_SIZE = 20;

const static int MAXIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR = 5;
const static int MINIMUM_NUM_OF_SOCIAL_EVENT_IN_A_HOUR = 2;

const static float EXECUTE_SOCIAL_EVENT = 0.5;
const static float EXECUTE_METTING_EVENT = 0.7;

/* the probability of transfering from susceptible to presymptomatic 
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;
const static float INFECTIOUS_TO_ASYMPTOMATIC = 0.2;

/* It may take 1 ~ 14 days to show symtoms */
const static float PRESYMPTOMATIC_TO_MILD = 0.25;
const static float ASYMPTOMATIC_TO_RECOVERED = 0.3;

const static float MILD_TO_SEVERE = 0.3;
const static float MILD_TO_RECOVERED = 0.3;

const static float SEVERE_TO_RECOVERED = 0.3;
const static float SEVERE_TO_DEAD = 0.1;

// P{ i get infect when agent j state is mild} = a
const static float INFECTION_RATE_MILD = 0.3;
// P{ i get infect when agent j state is severe} = b
const static float INFECTION_RATE_SEVERE = 0.3;
// P{ i get infect when agent j state is presymptomatic} = c
const static float INFECTION_RATE_PRESYMPTOMATIC = 0.4;
// P{ i get infect when agent j state is asymptomatic} = d
const static float INFECTION_RATE_ASYMPTOMATIC = 0.4;

#endif