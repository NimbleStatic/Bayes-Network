#ifndef NODE_BUILDING_BLOCKS_H
#define NODE_BUILDING_BLOCKS_H

#include <string>

class ObjectID
{
private:
    static unsigned int ids_created;
    const unsigned int id;

public:
    ObjectID();
    unsigned int get_id() const;
};

class NodeState
{
private:
    unsigned int state_nr;
    std::string state_description;

public:
    NodeState(unsigned int state_nr, std::string state_description);
    void set_description(std::string state_description);
    void set_state_nr(unsigned int state_nr);
    unsigned int get_state_nr() const;
    std::string get_description() const;
    bool operator==(const NodeState other) const;
};

#endif