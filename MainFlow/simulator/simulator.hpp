#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "../time/hpp/clock.hpp"
#include "../agent/hpp/agent.hpp"
#include "../event_generator/event_generator.hpp"

class Simulator {

private:
    static Clock* clock;
    static Agent* network;
    static EventGenerator* eventGenerator;
    void init_network();
    void init_agents();
    void print_network();
    void agentEventExecution();
    void updateAgentState();
public:
    Simulator(Clock* clock, Agent* network, EventGenerator* eventGenerator);
    void start();
};

#endif
