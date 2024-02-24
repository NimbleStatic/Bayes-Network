#include "node_building_blocks.h"

#include <string>

unsigned int ObjectID::ids_created = 1;
ObjectID::ObjectID() : id(ids_created++){};

unsigned int ObjectID::get_id() const
{
    return id;
};

bool ObjectID::operator==(const ObjectID other) const
{
    return (this->get_id() == other.get_id());
}

NodeState::NodeState(unsigned int state_nr, std::string state_description, ObjectID node_id) : state_nr(state_nr), state_description(state_description), node_id(node_id)
{
}

void NodeState::set_description(std::string state_description)
{
    this->state_description = state_description;
}
void NodeState::set_state_nr(unsigned int state_nr)
{
    this->state_nr = state_nr;
}
unsigned int NodeState::get_state_nr() const
{
    return state_nr;
}
unsigned int NodeState::get_node_id() const
{
    return node_id.get_id();
}
std::string NodeState::get_description() const
{
    return state_description;
}

std::string NodeState::get_string_representation() const
{
    std::string str;
    str += "N" + std::to_string(node_id.get_id()) + " ";
    str += "s" + std::to_string(state_nr) + " ";
    str += state_description;
    return str;
}

bool NodeState::operator==(const NodeState other) const
{
    return ((this->state_nr == other.state_nr) && (this->node_id == other.node_id));
}
