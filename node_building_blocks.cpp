#include "node_building_blocks.h"

#include <string>

ObjectID::ObjectID()
{
    id = ids_created;
    ids_created++;
};

unsigned int ObjectID::get_id()
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
unsigned int NodeState::get_state_nr()
{
    return state_nr;
}
std::string NodeState::get_description()
{
    return state_description;
}
