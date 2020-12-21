#include "params.hpp"
#include <random>
#include <omp.h>




std::default_random_engine DEFAULT_RANDOM_ENGINE;

int MAX_NUM_OF_THREADS = omp_get_max_threads();

int NUM_OF_SUSCEPTIBLE = 0;
int NUM_OF_PRESYMPTOMATIC = 0;
int NUM_OF_ASYMPTOMATIC = 0;
int NUM_OF_MILD = 0;
int NUM_OF_SEVERE = 0;
int NUM_OF_RECOVERED = 0;
int NUM_OF_DEATH = 0;


