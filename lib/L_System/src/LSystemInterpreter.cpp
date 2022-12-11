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

    // It should check that all productions are valid
    // the “isValidProduction” function above.
    for (auto i = this->productions.begin(); i != this->productions.end(); ++i) {
        if (!isValidProduction(static_cast<Production<char>>(*i), this->alphabet)) {
            throw std::invalid_argument("productions must be valid on the alphabet");
        }
    }

    // The constructor should also check that
    // every production has a unique predecessor.
    if (!isUniqueProductionSet(productions)) {
        throw std::invalid_argument("productions successors and predecessor must be unique!");
    }
}

template<typename SymbolType>
std::vector<SymbolType> LSystemInterpreter<SymbolType>::generate(unsigned long iterations) {
// We iterate x amount of times over the axiom.

    std::vector<SymbolType> newAxiom;

    if (iterations <= 0)
        return newAxiom;

    //definitely 1 iteration
    for (SymbolType symbol: this->axiom) {
        for (Production<SymbolType> p: this->productions) {
            if (p.getPredecessor() == symbol) {
                // If symbol found
                // add to vector
                for(SymbolType c :p.getSuccessor()){
                    newAxiom.push_back(c);
                }
                //dit werkt niet. Vragen aan lector
                //newAxiom.insert(std::end(newAxiom), std::begin(p.getSuccessor()), std::end(p.getSuccessor()));

            }
            //if not continue loop
        }
    }

    // When there are more than 1 iterations, we iterate over the created output
    for (size_t i = 1; i < iterations; ++i) {
        //make a copy so no bad pointer show up
        std::vector<SymbolType> temp_Axiom = newAxiom;

        //clear the new axiom for fresh start?
        newAxiom.clear();

        for (SymbolType symbol: temp_Axiom) {
            for (Production<SymbolType> p: this->productions) {
                if (p.getPredecessor() == symbol) {
                    // If symbol found
                    // add to vector
                    for(SymbolType c :p.getSuccessor()){
                        newAxiom.push_back(c);
                    }
                    //newAxiom.insert(newAxiom.end(), p.getSuccessor().begin(), p.getSuccessor().end());
                }
                //if not continue loop
            }
        }
    }
    return newAxiom;
}

template
class LSystemInterpreter<char>;