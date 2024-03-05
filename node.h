#ifndef PROPABILITY_MANAGERS_H
#define PROPABILITY_MANAGERS_H
#include "node_building_blocks.h"
#include "node_propability_table.h"
#include <memory>
#include <map>
#include <vector>
#include <unordered_set>

class Node
{
private:
    ObjectID id;
    std::vector<ObjectID> parent_node_ids;
    std::vector<std::shared_ptr<NodeState>> possible_states;
    std::shared_ptr<NodeState> current_state;
    unsigned int dependance_depth;
    bool is_undefined;
    bool is_dependant;
    NodePropabilityTable node_propabilities;

public:
    bool add_parent_node(std::shared_ptr<Node> const);
    void add_possible_state(NodeState new_state);
    bool del_parent_node(std::shared_ptr<Node> const);
    void del_possible_state(NodeState new_state);
}

#endif