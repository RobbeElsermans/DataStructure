//
// Created by robbeelsermans on 12/5/22.
//

#include <stdexcept>
#include "../include/LSystemInterpreter.h"
#include "../include/Validation.h"


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
    for (SymbolType value: productions) {
        if (isValidProduction(value, alphabet)) {

        } else {
            // If any of the productions are invalid,
            // it should throw an exception.
            std::invalid_argument("productions must be valid on the alphabet");
            break;
        }
    }

    // The constructor should also check that
    // every production has a unique predecessor.


}

template<typename SymbolType>
std::vector<SymbolType> LSystemInterpreter<SymbolType>::generate(unsigned long iterations) {
    return std::vector<SymbolType>();
}
