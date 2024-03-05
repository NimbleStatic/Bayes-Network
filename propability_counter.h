#ifndef PROPABILITY_COUNTER_H
#define PROPABILITY_COUNTER_H
#include "node_building_blocks.h"
#include <memory>
#include <map>
#include <vector>
#include <unordered_set>

class PropabilityCounter
{
private:
    std::map<std::shared_ptr<NodeState>, unsigned int> outcome_propability_counts;
    std::vector<std::shared_ptr<NodeState>> possible_states;

    unsigned int _get_full_count() const;
    bool _is_state_in_system(std::shared_ptr<NodeState> state) const;

public:
    PropabilityCounter(std::vector<std::shared_ptr<NodeState>> states);
    PropabilityCounter();

    void set_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier);

    void update_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier);
    void update_propability(std::shared_ptr<NodeState> state, unsigned int weight);
    void update_propability(std::shared_ptr<NodeState> state);

    float get_propability(std::shared_ptr<NodeState> state) const;
    std::vector<float> get_propabilities(std::vector<std::shared_ptr<NodeState>> states) const;

    std::shared_ptr<NodeState> choose_state() const;

    // When adding states the default propability count is 1
    bool add_state(std::shared_ptr<NodeState> new_state, unsigned int state_count);
    bool add_state(std::shared_ptr<NodeState> new_state);
    void add_states(std::vector<std::shared_ptr<NodeState>> new_states);
    bool delete_state(std::shared_ptr<NodeState> state);
    void delete_states(std::vector<std::shared_ptr<NodeState>> states);

    std::string get_description() const;
};

#endif;