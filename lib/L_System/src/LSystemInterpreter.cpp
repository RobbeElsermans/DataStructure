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

    //TODO check axiom that all items are in alphabet

    // It should check that all productions are valid
    // the “isValidProduction” function above.
    for (auto i = this->productions.begin(); i != this->productions.end(); ++i) {
        if (!isValidProduction(static_cast<Production<SymbolType>>(*i), this->alphabet)) {
            throw std::invalid_argument("productions must be valid on the alphabet");
        }
    }

    // The constructor should also check that
    // every production has a unique predecessor.
    if (!isUniqueProductionSet(productions)) {
        throw std::invalid_argument("productions successors and predecessor must be unique!");
    }

    // The constructor should also check that
    // every axiom item is in the alphabet.
    if (!isValidAxiom(axiom, alphabet)) {
        throw std::invalid_argument("Axiom is not valid!");
    }

    // It should also check that there is a Production for
    // each symbol in the alphabet.
    // If there is a symbol in the alphabet without a production, add a production with that symbol
    this->productions = isInAlphabet(productions, alphabet);
    //std::printf("test");
}

template<typename SymbolType>
std::vector<SymbolType> LSystemInterpreter<SymbolType>::generate(unsigned long iterations) {
// We iterate x amount of times over the axiom.

    std::vector<SymbolType> newAxiom;

    if (iterations <= 0)
        return newAxiom;

    //definitely 1 iteration
    for (SymbolType symbol: this->axiom) {
        //bool if no production is found
        bool hasProduction = false;
        for (Production<SymbolType> p: this->productions) {

            if (p.getPredecessor() == symbol) {
                hasProduction = true;
                // If symbol found
                // add to vector
                for(SymbolType c :p.getSuccessor()){
                    newAxiom.push_back(c);
                }
                //dit werkt niet. Vragen aan lector
                //newAxiom.insert(std::end(newAxiom), std::begin(p.getSuccessor()), std::end(p.getSuccessor()));

            }

        }

        //if no production is found, add the value to it
        if(!hasProduction)
        {
            newAxiom.push_back(symbol);
        }
    }

    // When there are more than 1 iterations, we iterate over the created output
    for (size_t i = 1; i < iterations; ++i) {
        //make a copy so no bad pointer show up
        std::vector<SymbolType> temp_Axiom = newAxiom;

        //clear the new axiom for fresh start?
        newAxiom.clear();

        for (SymbolType symbol: temp_Axiom) {
            //bool if no production is found
            bool hasProduction = false;
            for (Production<SymbolType> p: this->productions) {
                if (p.getPredecessor() == symbol) {
                    hasProduction = true;
                    // If symbol found
                    // add to vector
                    for(SymbolType c :p.getSuccessor()){
                        newAxiom.push_back(c);
                    }
                    //newAxiom.insert(newAxiom.end(), p.getSuccessor().begin(), p.getSuccessor().end());
                }
                //if not continue loop
            }
            //if no production is found, add the value to it
            if(!hasProduction)
            {
                newAxiom.push_back(symbol);
            }
        }
    }
    return newAxiom;
}

template
class LSystemInterpreter<char>;

template
class LSystemInterpreter<int8_t>;