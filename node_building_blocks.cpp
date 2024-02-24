#include "node_building_blocks.h"

#include <string>
unsigned int ObjectID::ids_created = 0;
ObjectID::ObjectID() : id(ids_created++){};

unsigned int ObjectID::get_id() const
{
    return id;
};

NodeState::NodeState(unsigned int state_nr, std::string state_description) : state_nr(state_nr), state_description(state_description)
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
std::string NodeState::get_description() const
{
    return state_description;
}

bool NodeState::operator==(const NodeState other) const
{
    if ((this->state_nr) == (other.state_nr))
    {
        return true;
    }
    return false;
}
