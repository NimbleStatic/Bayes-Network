#ifndef NODE_PROPABILITY_TABLE_H
#define NODE_PROPABILITY_TABLE_H
#include "node_building_blocks.h"
#include "propability_counter.h"
#include <memory>
#include <map>
#include <vector>
#include <unordered_set>

class NodePropabilityTable
{
private:
    // independant propability is represented by an unordered set with nullptr
    std::map<std::unordered_set<std::shared_ptr<NodeState>>, PropabilityCounter> parent_state_p_counters;
    std::map<ObjectID, std::vector<std::shared_ptr<NodeState>>> parent_states;
    std::vector<std::shared_ptr<NodeState>> node_states;

    std::vector<std::unordered_set<std::shared_ptr<NodeState>>> _generate_all_possible_parent_combinations(std::map<ObjectID, std::vector<std::shared_ptr<NodeState>>> parent_states) const;
    std::map<std::unordered_set<std::shared_ptr<NodeState>>, PropabilityCounter> _make_inherited_propability_counters(std::vector<std::unordered_set<std::shared_ptr<NodeState>>> all_parent_combinations) const;

public:
    NodePropabilityTable(std::vector<std::shared_ptr<NodeState>> parent_states, std::vector<std::shared_ptr<NodeState>> node_states);
    NodePropabilityTable(std::vector<std::shared_ptr<NodeState>> parent_states);
    NodePropabilityTable();

    bool add_parent_state(std::shared_ptr<NodeState> state);
    bool delete_parent_state(std::shared_ptr<NodeState> state);
    bool add_node_state(std::shared_ptr<NodeState> state);
    bool delete_node_state(std::shared_ptr<NodeState> state);

    float get_propability(std::unordered_set<std::shared_ptr<NodeState>> parent_states, std::shared_ptr<NodeState> outcome_state) const;

    void update_counter(std::unordered_set<std::shared_ptr<NodeState>> parent_states, std::shared_ptr<NodeState> outcome_state, unsigned int weight);
    void update_counter(std::unordered_set<std::shared_ptr<NodeState>> parent_states, std::shared_ptr<NodeState> outcome_state);
    void update_counters(std::unordered_set<std::shared_ptr<NodeState>> parent_states, std::vector<std::shared_ptr<NodeState>> outcome_states);

    std::shared_ptr<NodeState> choose_state(std::unordered_set<std::shared_ptr<NodeState>> parent_states) const;

    // access independent propabilities with a unordered_set<nullptr>
    float get_propability(std::shared_ptr<NodeState> outcome_state) const;

    void update_counter(std::shared_ptr<NodeState> outcome_state, unsigned int weight);
    void update_counter(std::shared_ptr<NodeState> outcome_state);
    void update_counters(std::vector<std::shared_ptr<NodeState>> outcome_states);

    std::shared_ptr<NodeState> choose_state() const;

    std::string get_description() const;
};
#endif;