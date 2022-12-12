//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_LSYSTEMINTERPRETER_HPP
#define DATASTRUCTURE_LSYSTEMINTERPRETER_HPP

#include <vector>
#include <unordered_set>
#include "Production.hpp"
#include "Validation.hpp"
#include "HelpFunctions.hpp"

/**
 * This class represents the actual L-System.
 * @tparam SymbolType
 * @description  It contains an axiom (Initial state),
 * A set of productions (Replacement rules) and an alphabet (List of allowed symbols).
 */
template <typename SymbolType>
class LSystemInterpreter {
public:

  /**
   * This constructor takes an axiom, a set of productions and
   * an alphabet and stores these in the fields.
   * @param axiom
   * @param productions
   * @param alphabet
   *
   * @description
   * It should check that all productions are valid using
   * the “isValidProduction” function.
   * If any of the productions are invalid,
   * it should throw an exception.
   *
   * @description
   * The constructor should also check that
   * every production has a unique predecessor.
   * It should also check that there is a L_System for
   * each symbol in the alphabet.
   * If there is a symbol in the alphabet without a production,
   * you can decide what to do:
   * 1. Throw an exception
   * 2. Add an identity production (A -> A)
   */
    LSystemInterpreter(const std::vector<SymbolType>& axiom, const std::unordered_set<Production<SymbolType>>& productions, const std::unordered_set<SymbolType>& alphabet);

/**
 * This function should execute `iterations` iterations of the L-System.
 * @param iterations
 * @return
 */
    std::vector<SymbolType> generate(unsigned long iterations);

private:
    std::vector<SymbolType> axiom;
    std::unordered_set<Production<SymbolType>> productions;
    std::unordered_set<SymbolType> alphabet;

    //We use vector because we are only including at the end of it.
    std::vector<SymbolType> generatedSystem;
};


#endif //DATASTRUCTURE_LSYSTEMINTERPRETER_HPP
