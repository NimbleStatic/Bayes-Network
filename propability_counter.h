#ifndef PROPABILITY_MANAGERS_H
#define PROPABILITY_MANAGERS_H
#include "node_building_blocks.h"
#include <memory>
#include <map>
#include <vector>
#include <unordered_set>

using NStatePtr = std::shared_ptr<NodeState>;

class PropabilityCounter
{
private:
    std::map<NStatePtr, unsigned int> outcome_propability_counts;
    std::vector<NStatePtr> possible_states;

    unsigned int _get_full_count() const;
    bool _is_state_in_system(NStatePtr state) const;

public:
    PropabilityCounter(std::vector<NStatePtr> states);
    PropabilityCounter();

    void set_propability(NStatePtr state, float propability, unsigned int const_multiplier);

    void update_propability(NStatePtr state, float propability, unsigned int const_multiplier);
    void update_propability(NStatePtr state, unsigned int weight);
    void update_propability(NStatePtr state);

    float get_propability(NStatePtr state) const;
    std::vector<float> get_propabilities(std::vector<NStatePtr> states) const;

    NStatePtr choose_state() const;

    // When adding states the default propability count is 1
    bool add_state(NStatePtr new_state, unsigned int state_count);
    bool add_state(NStatePtr new_state);
    void add_states(std::vector<NStatePtr> new_states);
    bool delete_state(NStatePtr state);
    void delete_states(std::vector<NStatePtr> states);

    std::string get_description() const;
};

#endif