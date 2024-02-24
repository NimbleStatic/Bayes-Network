#include <map>
#include <memory>
#include "propability_managers.h"
#include <vector>
#include <cmath>
#include <random>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <sstream>

unsigned int PropabilityCounter::_get_full_count() const
{
    unsigned int full_count = 0;
    for (const auto &key_value : outcome_propability_counts)
    {
        full_count += key_value.second;
    };
    return full_count;
}

bool PropabilityCounter::_is_state_in_system(std::shared_ptr<NodeState> state) const
{
    for (std::shared_ptr<NodeState> system_state : possible_states)
    {
        if (*system_state == *state)
        {
            return true;
        };
    }
    return false;
}

PropabilityCounter::PropabilityCounter(std::vector<std::shared_ptr<NodeState>> states)
{
    add_states(states);
}

PropabilityCounter::PropabilityCounter()
{
}

void PropabilityCounter::set_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier)
{
    unsigned int weight = std::round((propability * const_multiplier));
    outcome_propability_counts[state] = weight;
}
void PropabilityCounter::update_propability(std::shared_ptr<NodeState> state, float propability, unsigned int const_multiplier)
{
    unsigned int weight = std::round((propability * const_multiplier));
    update_propability(state, weight);
}
void PropabilityCounter::update_propability(std::shared_ptr<NodeState> state, unsigned int weight)
{
    outcome_propability_counts[state] += weight;
}
void PropabilityCounter::update_propability(std::shared_ptr<NodeState> state)
{
    update_propability(state, 1);
}

float PropabilityCounter::get_propability(std::shared_ptr<NodeState> state) const
{
    unsigned int prob_counter;
    auto it = outcome_propability_counts.find(state);
    if (it != outcome_propability_counts.end())
    {
        prob_counter = it->second;
    }
    else
    {
        // @TODO add custom exception no state in the state map
        throw std::out_of_range("State not found in the state map");
    };
    unsigned int all_counts = _get_full_count();
    float prob = static_cast<float>(prob_counter) / static_cast<float>(all_counts);
    return prob;
}
std::vector<float> PropabilityCounter::get_propabilities(std::vector<std::shared_ptr<NodeState>> states) const
{
    std::vector<float> propabilities;
    for (std::shared_ptr<NodeState> state : states)
    {
        propabilities.push_back(get_propability(state));
    };
    return propabilities;
}
std::shared_ptr<NodeState> PropabilityCounter::choose_state() const
{

    std::vector<float> propabilities = get_propabilities(possible_states);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<int> prop_distribution(propabilities.begin(), propabilities.end());

    std::size_t rand_ind = prop_distribution(gen);
    std::shared_ptr<NodeState> rand_state = possible_states[rand_ind];
    return rand_state;
}

bool PropabilityCounter::add_state(std::shared_ptr<NodeState> new_state, unsigned int state_count)
{
    if (!_is_state_in_system(new_state))
    {
        possible_states.push_back(new_state);
        outcome_propability_counts[new_state] = state_count;
        return true;
    };
    return false;
}
bool PropabilityCounter::add_state(std::shared_ptr<NodeState> new_state)
{
    return add_state(new_state, 1);
}
void PropabilityCounter::add_states(std::vector<std::shared_ptr<NodeState>> new_states)
{
    for (std::shared_ptr<NodeState> state : new_states)
    {
        add_state(state);
    };
}
bool PropabilityCounter::delete_state(std::shared_ptr<NodeState> state)
{
    if (_is_state_in_system(state))
    {
        auto it = std::find(possible_states.begin(), possible_states.end(), state);
        auto it_m = outcome_propability_counts.find(state);

        if ((it != possible_states.end()) && (it_m != outcome_propability_counts.end()))
        {
            possible_states.erase(it);
            outcome_propability_counts.erase(it_m);
            return true;
        }
        else if (it == possible_states.end())
        {
            throw std::runtime_error(" there is state in system but it isnt findable");
        }
        else if (it_m == outcome_propability_counts.end())
        {
            throw std::runtime_error(" there is state in possible_states but not in propability_outocomes");
        };
    }
    return false;
}
void PropabilityCounter::delete_states(std::vector<std::shared_ptr<NodeState>> states)
{
    for (std::shared_ptr<NodeState> state : states)
    {
        delete_state(state);
    };
}

std::string PropabilityCounter::get_description() const
{
    std::ostringstream oss;
    for (const auto key_val : outcome_propability_counts)
    {
        std::shared_ptr<NodeState> state = key_val.first;
        oss << state->get_string_representation() << " - count:" << key_val.second;
        oss << ", propability:" << get_propability(state) << std::endl;
    };
    return oss.str();
}
