//
// Created by robbeelsermans on 12/5/22.
//

#include <stdexcept>
#include <iostream>
#include "../include/LSystemInterpreter.hpp"
#include "../include/Validation.hpp"
#include "../include/HelpFunctions.hpp"


template<typename SymbolType>
LSystemInterpreter<SymbolType>::LSystemInterpreter(const std::vector<SymbolType> &axiom,
                                                   const std::unordered_set<Production<SymbolType>> &productions,
                                                   const std::unordered_set<SymbolType> &alphabet) {
    // This constructor takes an axiom, a set of productions and
    // an alphabet and stores these in the fields.
    this->alphabet = alphabet;
    this->productions = productions;
    this->axiom = axiom;

    // It should check that all productions are valid using
    // the “isValidProduction” function above.
    for (auto i = this->productions.begin(); i != this->productions.end(); ++i) {
        if(!isValidProduction(static_cast<Production<char>>(*i), this->alphabet)){

            throw std::invalid_argument("productions must be valid on the alphabet");
            while(1);
            //break;
        }
    }

    // The constructor should also check that
    // every production has a unique predecessor.
    if(!isUniqueProductionSet(productions)){
        throw std::invalid_argument("productions successors must be unique");
        while(1);
    }
}

template<typename SymbolType>
std::vector<SymbolType> LSystemInterpreter<SymbolType>::generate(unsigned long iterations) {
    return std::vector<SymbolType>();
}

template class LSystemInterpreter<char>;