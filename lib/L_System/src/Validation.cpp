//
// Created by robbeelsermans on 12/5/22.
//

#include <iostream>
#include "../include/Validation.hpp"
#include "../include/HelpFunctions.hpp"


template<typename SymbolType>
bool isValidProduction(const Production<SymbolType> &production, const std::unordered_set<SymbolType> &alphabet) {
    //check if all values are in the alphabet
    Production<SymbolType> p = production;

    //reference: https://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset

    //Check that predecessor is in alphabet
    if(alphabet.find(p.getPredecessor()) == alphabet.end()){
        throw std::invalid_argument("Not all items are in alphabet!");
    }

    //Check that successor is in alphabet
    bool isInSuccessor;
    for(SymbolType a : p.getSuccessor()){
        if(alphabet.find(a) == alphabet.end()){
            // If there is a symbol in the alphabet without a production,
            // you can decide what to do:
            //
            //    1. Throw an exception
            throw std::invalid_argument("Not all items are in alphabet!");
            //    2. Add an identity production (A -> A)
            //TODO probeer dit ook eens
            //return false;
        }
    }

    return true;
}


template <typename SymbolType>
bool isUniqueProductionSet(const std::unordered_set<Production<SymbolType>>& production){
    //The counter may never be greater than 1 because if it is greater than 1, duplicated successors are in the set.
    std::unordered_set<Production<SymbolType>> p = production;
    size_t counter = 0;

    //check the predecessors
    for(Production<SymbolType> value : p){
        counter = 0;

        for(Production<SymbolType> value2 : p){
            if(value.getPredecessor() == value2.getPredecessor())
            {
                ++counter;
            }
            if(counter > 1)
                return false;
        }
    }

    //check the successors
    for(Production<SymbolType> value : p){
        counter = 0;
        for(Production<SymbolType> value2 : p){
            if(value.getSuccessor() == value2.getSuccessor())
            {
                ++counter;
            }
            if(counter > 1)
                return false;
        }
    }

    return true;
}

//Explicit declaration
template bool isValidProduction(const Production<char> &production, const std::unordered_set<char> &alphabet);
template bool isUniqueProductionSet(const std::unordered_set<Production<char>>& production);
