//
//  Agent.hpp
//  AgentDesign
//
//  Created by Cayden on 2020/12/10.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <stdio.h>
#include <vector>

class Agent
{
private:
    int id;
    int wellness;
    int nextState;
    std::vector<Agent> neigbhours;
public:
    Agent(int number); // construction function
    int getId();
    int getWellness();
    int getNextState();
    // todo: getEvent
    // todo: setEvent
    void executeEvent();
    void updateWellness();
    std::vector<Agent> getNeigbhours();
};

#endif /* Agent_hpp */
