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
    const bool isInPredecessor = alphabet.find(p.getPredecessor()) != alphabet.end();

    /*
    bool isInSuccessor = false;
    for (SymbolType value: p.getSuccessor()) {
        if (alphabet.find(value) != alphabet.end()) {
            isInSuccessor = true;
        }
        else{
            //Als er 1 fout in zit, stoppen want ze moeten allen in het alphabet voorkomen.
            isInSuccessor = false;
            break;
        }
    }
     */

    return isInPredecessor; //&& isInSuccessor;
}

template <typename SymbolType>
bool isUniqueProductionSet(const std::unordered_set<Production<SymbolType>>& production){
    //The counter may never be greater than 1 because if it is greater than 1, duplicated successors are in the set.
    std::unordered_set<Production<SymbolType>> p = production;
    size_t counter = 0;

    for(Production<SymbolType> value : p){
        counter = 0;
        for(Production<SymbolType> value2 : p){
            if(value.getSuccessor() == value2.getSuccessor())
            {
                ++counter;
                //std::cout << value.getSuccessor().back() << std::endl;
                //std::cout << value2.getSuccessor().back() << std::endl;
                //std::cout << std::endl;
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
