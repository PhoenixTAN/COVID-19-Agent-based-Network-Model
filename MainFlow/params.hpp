#ifndef PARAMS_H
#define PARAMS_H

#include <algorithm>    // std::max
#include <random>

/* used for normal distribution*/
extern std::default_random_engine DEFAULT_RANDOM_ENGINE;

const static unsigned int RANDOM_SEED = 10;

/* OpenMP parallel computing */
extern int MAX_NUM_OF_THREADS;

/* Network */
const static int SIMULATION_DAYS = 365;
const static int NETWORK_SIZE = 30000;  

/* Event generator */
const static int MAXIMUM_NUM_OF_AGENTS_EACH_SOCIAL_EVENT = 40;
const static int MINIMUM_NUM_OF_AGENTS_SOCIAL_EVENT = 10;
const static float EXECUTE_METTING_EVENT = 0.7;
const static float EXECUTE_SOCIAL_EVENT = 0.5;
const static int NUM_OF_MEETING_EACH_HOUR = 40;
const static int NUM_OF_SOCIAL_EACH_HOUR = 70;

/* P{ i get infect when agent j state is mild} = a */
const static float INFECTION_RATE_MILD = 0.5;
/* P{ i get infect when agent j state is severe} = b */
const static float INFECTION_RATE_SEVERE = 0.6;
/* P{ i get infect when agent j state is presymptomatic} = c */
const static float INFECTION_RATE_PRESYMPTOMATIC = 0.4;
/* P{ i get infect when agent j state is asymptomatic} = d */
const static float INFECTION_RATE_ASYMPTOMATIC = 0.3;

/* the probability of transferring from susceptible to presymptomatic/asymptomatic
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;
const static float INFECTIOUS_TO_ASYMPTOMATIC = 0.2;

/* It may take 1 ~ 14 days to show symtoms */
static int INITIAL_NUM_OF_PRESYMTOMATIC = std::max(10, NETWORK_SIZE / 2000);
const static int MAX_INCUBATION_PEROID = 14;        // days
const static int MIN_INCUBATION_PERIOD = 3;         // days
const static int INCUBATION_EXPECTATION = 7;        // days
const static int INCUBATION_VARIANCE = 2;           // days

/* Asymptomatic */
const static int MAX_ASYMPTOMATIC_PERIOD = 13;      // days
const static int MIN_ASYMPTOMATIC_PEROID = 5;       // days

/* after this period, agent will have a high probability to get severe */
const static int MAX_MILD_PERIOD = 9;       // days
const static int MIN_MILD_PERIOD = 4;       // days
const static float MILD_TO_SEVERE = 0.6;    // probability

/* after this period, agent will have a high period to die */
const static int MAX_SEVERE_PERIOD = 9;         // days
const static int MIN_SEVERE_PERIOD = 4;         // days
const static float SEVERE_TO_DEAD = 0.03;       // probability

#endif
