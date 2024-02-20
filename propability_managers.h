#ifndef PROPABILITY_MANAGERS_H
#define PROPABILITY_MANAGERS_H
#include <node_building_blocks.h>
#include <memory>
#include <map>

// class PropabilityRepresantation
// {
// private:
//     unsigned int propability_count;
//     std::shared_ptr<NodeState> outcome_state;

// public:
//     int get_propability_count();
//     void set_propability_count(unsigned int new_count);
//     void update_propability_count(unsigned int value);
//     PropabilityRepresantation(std::shared_ptr<NodeState> outcome_state);
//     std::shared_ptr<NodeState> get_state_referenced();
// };

class PropabilityCounter
{
private:
    std::map<NodeState, unsigned int> outcome_propability_counts;
}
#endif