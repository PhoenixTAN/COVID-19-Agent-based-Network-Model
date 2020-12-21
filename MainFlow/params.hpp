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
const static int SIMULATION_DAYS = 100;
const static int NETWORK_SIZE = 200000;  

/* Event generator */
const static int MAXIMUM_NUM_OF_AGENTS_EACH_SOCIAL_EVENT = 50;
const static int MINIMUM_NUM_OF_AGENTS_SOCIAL_EVENT = 10;
const static float EXECUTE_METTING_EVENT = 0.7;
const static float EXECUTE_SOCIAL_EVENT = 0.5;
const static int NUM_OF_MEETING_EACH_HOUR = 40;
const static int NUM_OF_SOCIAL_EACH_HOUR = 70;

/* P{ i get infect when agent j state is mild} = a */
const static float INFECTION_RATE_MILD = 0.7;
/* P{ i get infect when agent j state is severe} = b */
const static float INFECTION_RATE_SEVERE = 0.8;
/* P{ i get infect when agent j state is presymptomatic} = c */
const static float INFECTION_RATE_PRESYMPTOMATIC = 0.6;
/* P{ i get infect when agent j state is asymptomatic} = d */
const static float INFECTION_RATE_ASYMPTOMATIC = 0.3;

/* the probability of transferring from susceptible to presymptomatic/asymptomatic
if get infected */
const static float INFECTIOUS_TO_PRESYMPTOMATIC = 0.8;
const static float INFECTIOUS_TO_ASYMPTOMATIC = 0.2;

/* It may take 1 ~ 14 days to show symtoms */
static int INITIAL_NUM_OF_PRESYMTOMATIC = std::min(10, NETWORK_SIZE);
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
const static float SEVERE_TO_DEAD = 0.1;       // probability

/* intervention level */

/* level 1: people get infected, having obvious symtoms */
const static int THRESHOLD_OF_MILD_SEVERE = 100;

/* level 2: many people get infected */
const static int THRESHOLD2_OF_MILD_SEVERE = 500;

/* level 3: people die */
const static int THRESHOLD_OF_DEATH = 10;

/* level 4: many people die */
const static int THRESHOLD2_OF_DEATH = 100;

/* level 5: it is threatening humanity */
const static float THRESHOLD3_OF_DEATH = 0.01;  /* 1% people die */


const static float FACTOR_OF_EVENTS[6] = {1.0, 0.9, 0.7, 0.5, 0.3, 0.1};


/* when people know themselves positive, lower the probability to an event */

/* statistics */
extern int NUM_OF_SUSCEPTIBLE;
extern int NUM_OF_PRESYMPTOMATIC;
extern int NUM_OF_ASYMPTOMATIC;
extern int NUM_OF_MILD;
extern int NUM_OF_SEVERE;
extern int NUM_OF_RECOVERED;
extern int NUM_OF_DEATH;

#endif
