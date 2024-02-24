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
    bool operator==(const ObjectID other) const;
};

class NodeState
{
private:
    unsigned int state_nr;
    ObjectID node_id;
    std::string state_description;

public:
    NodeState(unsigned int state_nr, std::string state_description, ObjectID node_id);
    void set_description(std::string state_description);
    void set_state_nr(unsigned int state_nr);
    unsigned int get_node_id() const;
    unsigned int get_state_nr() const;
    std::string get_description() const;
    std::string get_string() const;

    bool operator==(const NodeState other) const;
};

#endif