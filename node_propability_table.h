#ifndef PROPABILITY_MANAGERS_H
#define PROPABILITY_MANAGERS_H
#include "node_building_blocks.h"
#include "propability_counter.h"

#include <memory>
#include <map>
#include <vector>
#include <unordered_set>

using NStatePtr = std::shared_ptr<NodeState>;

class NodePropabilityTable
{
private:
    // independant propability is represented by an unordered set with nullptr
    std::map<std::unordered_set<NStatePtr>, PropabilityCounter> parent_state_p_counters;
    std::map<ObjectID, std::vector<NStatePtr>> parent_states;
    std::vector<NStatePtr> node_states;

    std::vector<std::unordered_set<NStatePtr>> _generate_all_possible_parent_combinations(std::map<ObjectID, std::vector<NStatePtr>> parent_states) const;
    std::map<std::unordered_set<NStatePtr>, PropabilityCounter> _make_inherited_propability_counters(std::vector<std::unordered_set<NStatePtr>> all_parent_combinations) const;

public:
    NodePropabilityTable(std::vector<NStatePtr> parent_states, std::vector<NStatePtr> node_states);
    NodePropabilityTable(std::vector<NStatePtr> parent_states);
    NodePropabilityTable();

    bool add_parent_state(NStatePtr state);
    bool delete_parent_state(NStatePtr state);
    bool add_node_state(NStatePtr state);
    bool delete_node_state(NStatePtr state);

    float get_propability(std::unordered_set<NStatePtr> parent_states, NStatePtr outcome_state) const;

    void update_counter(std::unordered_set<NStatePtr> parent_states, NStatePtr outcome_state, unsigned int weight);
    void update_counter(std::unordered_set<NStatePtr> parent_states, NStatePtr outcome_state);
    void update_counters(std::unordered_set<NStatePtr> parent_states, std::vector<NStatePtr> outcome_states);

    NStatePtr choose_state(std::unordered_set<NStatePtr> parent_states) const;

    // access independent propabilities with a unordered_set<nullptr>
    float get_propability(NStatePtr outcome_state) const;

    void update_counter(NStatePtr outcome_state, unsigned int weight);
    void update_counter(NStatePtr outcome_state);
    void update_counters(std::vector<NStatePtr> outcome_states);

    NStatePtr choose_state() const;

    std::string get_description() const;
};
#endif