#ifndef EVENT_GENERATOR_HPP
#define EVENT_GENERATOR_HPP

#include <set>
#include "../agent/hpp/agent.hpp"

/**
 * @Author Xueyan Xia
 * @description singleton pattern
*/
class EventGenerator
{
private:
    static std::set<int> agentSet;
    EventGenerator();
    static EventGenerator* instance;
public:
    void createAgentSet(Agent* network);
    void createSocialInterationEvents(Agent* network);
    void createMeetingEvents(Agent* network);
    static EventGenerator* getInstance();
};

#endif
