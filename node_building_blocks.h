#ifndef NODE_BUILDING_BLOCKS_H
#define NODE_BUILDING_BLOCKS_H

#include <string>

class ObjectID
{
private:
    static unsigned int ids_created;
    unsigned int id;

public:
    ObjectID();
    unsigned int get_id();
};

class NodeState
{
private:
    unsigned int state_nr;
    std::string state_description;

public:
    NodeState(unsigned int state_nr, std::string state_description);
    NodeState();
    void set_description(std::string state_description);
    void set_state_nr(unsigned int state_nr);
    unsigned int get_state_nr();
    std::string get_description();
};

#endif