//
// Created by robbeelsermans on 12/9/22.
//

#include <iostream>
#include "../include/HelpFunctions.hpp"

//Definition of the operator hash for a char production
namespace std{
    template<>
    std::size_t std::hash<Production<char>>::operator()(const Production<char> &production) const noexcept {
        Production<char> p = production;

        size_t id = 0;

        for(char val : p.getSuccessor()){
            id += p.getPredecessor() * val;
        }

        return (id);
    }
}

template<>
bool Production<char>::operator==(const Production<char> &production) const {
    return this->predecessor == production.predecessor;
}

namespace std{
    template<>
    std::size_t std::hash<Production<int8_t>>::operator()(const Production<int8_t> &production) const noexcept {
        Production<int8_t> p = production;

        size_t id = 0;

        for(int8_t val : p.getSuccessor()){
            id += p.getPredecessor() * val;
        }

        return (id);
    }
}

template<>
bool Production<int8_t>::operator==(const Production<int8_t> &production) const {
    return this->predecessor == production.predecessor;
}
