//
// Created by robbeelsermans on 12/9/22.
//

#include <iostream>
#include "../include/HelpFunctions.hpp"

//Definition of the operator hash
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

//template<typename SymbolType>
template<>
bool Production<char>::operator==(const Production<char> &production) const {
    return this->predecessor == production.predecessor;
}

//iterator
template <typename IteratorType>
Production<char> forwardIterate(IteratorType begin, IteratorType end)
{
    // TODO: Fill this in!

    //pointers hun waarde zijn irrelevant
    for (auto i = begin; i != end; i++) {
        std::cout << static_cast<Production<char>>(*i).getPredecessor()  << std::endl;
        return static_cast<Production<char>>(*i);
    }
}

template void forwardIterate(std::unordered_set<Production<char>>::iterator begin, std::unordered_set<Production<char>>::iterator end);

//template void forwardIterate(std::unordered_set<Production<char>>::iterator begin, std::unordered_set<Production<char>>::iterator end);
