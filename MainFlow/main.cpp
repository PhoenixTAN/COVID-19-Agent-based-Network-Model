#include <iostream>
#include <ctime>    /* time seed */
#include "params.hpp"
#include "agent/hpp/agent.hpp"
#include "event/hpp/event.hpp"
#include "time/hpp/clock.hpp"
#include "time/hpp/hour.hpp"
#include "statistics/statistics.hpp"
#include "event_generator/event_generator.hpp"
#include "simulator/simulator.hpp"


int main() {

    /* Initialize the clock */
    Clock* clock = Clock::getInstance();

    /* create the network */
    std::cout << "Creating network with size of " << NETWORK_SIZE << "." << std::endl;
    Agent* network = new Agent[NETWORK_SIZE];

    /* Event generator */
    EventGenerator* eventGenerator = EventGenerator::getInstance();

    std::cout<<"Setting up random seed: " << RANDOM_SEED << std::endl;
    srand(RANDOM_SEED);

    /* OpenMP */
    std::cout << "Using OpenMP library for parallel computing. Max thread: " << MAX_NUM_OF_THREADS << std::endl;

    Simulator* simulator = new Simulator(clock, network, eventGenerator);

    simulator->start();

    /* clean up */
    delete[] network;

}
