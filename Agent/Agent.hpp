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
    int number;
    int wellness;
    int nextState;
    std::vector<Agent> neigbhours;
public:
    Agent(int number); // construction function
    int getNumber();
    int getWellness();
    int getNextState();
    // todo:event
    void executeEvent();
    void updateWellness();
    std::vector<Agent> getNeigbhours();
};

#endif /* Agent_hpp */
