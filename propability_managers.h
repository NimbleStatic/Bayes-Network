#ifndef PROPABILITY_MANAGERS_H
#define PROPABILITY_MANAGERS_H
#include <node_building_blocks.h>
#include <memory>
#include <map>
#include <vector>

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
    std::map<std::shared_ptr<NodeState>, unsigned int> outcome_propability_counts;
    std::vector<std::shared_ptr<NodeState>> possible_states;

    unsigned int _get_full_count();

public:
    void set_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier);
    void update_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier);
    void update_propability(unsigned int weight);
    void update_propability();
    float get_propability(std::shared_ptr<NodeState> state);
    std::vector<float> get_propabilities(std::vector<std::shared_ptr<NodeState>> states);
    std::shared_ptr<NodeState> choose_state();

    bool add_state(std::shared_ptr<NodeState> new_state);
    void add_states(std::vector<std::shared_ptr<NodeState>> possible_states);
    bool delete_state(std::shared_ptr<NodeState> new_state);
    void delete_states(std::vector<std::shared_ptr<NodeState>> possible_states);
};

class NodePropabilityTable
{
private:
public:
};
#endif