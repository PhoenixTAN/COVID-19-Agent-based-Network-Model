#include "params.hpp"
#include <random>
#include <omp.h>




std::default_random_engine DEFAULT_RANDOM_ENGINE;

int MAX_NUM_OF_THREADS = omp_get_max_threads();

int numOfSusceptible = 0;
int numOfPresymptomatic = 0;
int numOfAsymptomatic = 0;
int numOfMild = 0;
int numOfRecovered = 0;
int numOfSevere = 0;
int numOfDead = 0;


