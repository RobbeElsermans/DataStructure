//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_LSYSTEMINTERPRETER_H
#define DATASTRUCTURE_LSYSTEMINTERPRETER_H

#include <vector>
#include <unordered_set>
#include "Production.h"

// This class represents the actual L-System.
// It contains an axiom (Initial state), A set of productions
// (Replacement rules) and an alphabet (List of allowed symbols).
template <typename SymbolType>
class LSystemInterpreter {
public:
// This constructor takes an axiom, a set of productions and
// an alphabet and stores these in the fields.

// It should check that all productions are valid using
// the “isValidProduction” function above.
// If any of the productions are invalid,
// it should throw an exception.

// The constructor should also check that
// every production has a unique predecessor.
// It should also check that there is a L_System for
// each symbol in the alphabet.
// If there is a symbol in the alphabet without a production,
// you can decide what to do:
//
   // 1. Throw an exception
//
  //  2. Add an identity production (A -> A)
    LSystemInterpreter(const std::vector<SymbolType>& axiom, const std::unordered_set<Production<SymbolType>>& productions, const std::unordered_set<SymbolType>& alphabet);

// This function should execute `iterations` iterations of
// the L-System.
//
// Be careful when applying your productions!
// Your productions should always be applied at the same time!
//
// An example:
// We have 2 productions: A -> AB, B -> A, and an axiom “ABA”
// We can apply the first production first, and get:
// “ABBAB”
// And then we can apply the second production, to get:
// “AAAAA”
// THIS IS WRONG!
//
// You should always execute all productions on the original text!
// So, in this case, the correct output would be:
// “ABAAB”
// (The first and last A’s were replaced by AB,
// and the middle B by A)
    std::vector<SymbolType> generate(unsigned long iterations);

private:
    const std::vector<SymbolType> axiom;
    const std::unordered_set<Production<SymbolType>> productions;
    const std::unordered_set<SymbolType> alphabet;
    //We use vector because we are only including at the end of it.
    std::vector<SymbolType> generatedSystem;
};


#endif //DATASTRUCTURE_LSYSTEMINTERPRETER_H
