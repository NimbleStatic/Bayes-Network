#ifndef NODE_BUILDING_BLOCKS_H
#define NODE_BUILDING_BLOCKS_H

#include <string>

class NodeID
{
private:
    unsigned int node_id;

public:
    NodeID();
    unsigned int get_id();

protected:
    unsigned int object_counter;
};

class NodeState
{
private:
    unsigned int state_nr;
    std::string state_description;

public:
    // 0 is always undefined
    void set_description(std::string state_description);
    void set_state_nr(unsigned int state_nr);
    // return 0 if undefined
    unsigned int get_state_nr();
    std::string get_description();
    bool is_undefined();
    void set_undefined();
    // state_nr == 0 --> undefined
};

#endif