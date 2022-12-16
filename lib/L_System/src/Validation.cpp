//
// Created by robbeelsermans on 12/5/22.
//

#include <iostream>
#include <algorithm>
#include "../include/Validation.hpp"
#include "../include/HelpFunctions.hpp"


template<typename SymbolType>
bool isValidProduction(const Production<SymbolType> &production, const std::unordered_set<SymbolType> &alphabet) {
    //check if all values are in the alphabet
    Production<SymbolType> p = production;

    //reference: https://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset

    //Check that predecessor is in alphabet
    if(alphabet.find(p.getPredecessor()) == alphabet.end())
        return false;

    //check if successors is in production
    for(SymbolType a : p.getSuccessor()){
        if(alphabet.find(a) == alphabet.end()){
            return false;
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

template <typename SymbolType>
std::unordered_set<Production<SymbolType>> isInAlphabet(const std::unordered_set<Production<SymbolType>>& productions, const std::unordered_set<SymbolType>& alphabet){
    std::unordered_set<Production<SymbolType>> temp_p = productions;

    for(SymbolType a: alphabet){
        //iterate over the productions
        bool isInside = false;
        for(Production<SymbolType> p : productions){
            if(p.getPredecessor() == a){
                isInside = true;
            }
        }

        if(!isInside)
        {
            //there is no production found so add one
            temp_p.insert(Production<SymbolType>(a, std::vector<SymbolType>{a}));
        }
    }
    return temp_p;
}

template <typename SymbolType>
bool isValidAxiom(const std::vector<SymbolType>& axiom, const std::unordered_set<SymbolType>& alphabet){
    //check if all values are in the alphabet
    std::vector<SymbolType> a = axiom;

    //check if axioms is in production
    for(SymbolType item : a){
        if(alphabet.find(item) == alphabet.end()){
            return false;
        }
    }

    return true;
}

//Explicit declaration char
template bool isValidProduction(const Production<char> &production, const std::unordered_set<char> &alphabet);
template bool isUniqueProductionSet(const std::unordered_set<Production<char>>& production);
template std::unordered_set<Production<char>> isInAlphabet(const std::unordered_set<Production<char>>& productions, const std::unordered_set<char>& alphabet);
template bool isValidAxiom(const std::vector<char>& axiom, const std::unordered_set<char>& alphabet);

//Explicit declaration int8_t
template bool isValidProduction(const Production<int8_t> &production, const std::unordered_set<int8_t> &alphabet);
template bool isUniqueProductionSet(const std::unordered_set<Production<int8_t>>& production);
template std::unordered_set<Production<int8_t>> isInAlphabet(const std::unordered_set<Production<int8_t>>& productions, const std::unordered_set<int8_t>& alphabet);
template bool isValidAxiom(const std::vector<int8_t>& axiom, const std::unordered_set<int8_t>& alphabet);