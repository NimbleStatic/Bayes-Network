#include <iostream>

#include <string>
#include "node_building_blocks.h"
#include "propability_counter.h"
#include <memory>

int main()
{
    ObjectID objId1;
    ObjectID objId2;

    std::cout << "ObjectID 1 ID: " << objId1.get_id() << std::endl;
    std::cout << "ObjectID 2 ID: " << objId2.get_id() << std::endl;

    // Testing NodeState
    NodeState state1(1, "State One", objId1);
    NodeState state2(2, "State Two", objId2);
    NodeState state3(3, "State Three", objId1);

    std::cout << "State 1 - Number: " << state1.get_state_nr() << ", Description: " << state1.get_description() << std::endl;
    std::cout << "State 2 - Number: " << state2.get_state_nr() << ", Description: " << state2.get_description() << std::endl;

    // std::cout << "hello world" << std::endl;
    PropabilityCounter my_count;
    std::cout << my_count.get_description() << std::endl;
    std::shared_ptr<NodeState> ptr1 = std::make_shared<NodeState>(state1);
    std::shared_ptr<NodeState> ptr2 = std::make_shared<NodeState>(state2);
    std::shared_ptr<NodeState> ptr3 = std::make_shared<NodeState>(state3);
    std::vector<std::shared_ptr<NodeState>> state_vec;
    state_vec.push_back(ptr3);
    state_vec.push_back(ptr1);
    state_vec.push_back(ptr2);
    state_vec.push_back(ptr3);
    my_count.add_state(ptr1, 8);
    std::cout << my_count.get_description() << std::endl;

    my_count.add_states(state_vec);
    std::cout << my_count.get_description() << std::endl;

    my_count.delete_state(ptr3);
    std::cout << my_count.get_description() << std::endl;

    my_count.delete_state(ptr3);
    std::cout << my_count.get_description() << std::endl;

    return 0;
};