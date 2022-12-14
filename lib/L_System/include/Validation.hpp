//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_VALIDATION_HPP
#define DATASTRUCTURE_VALIDATION_HPP

#include <unordered_set>
#include "Production.hpp"

/**
 * @description This function verifies that all symbols in the production
 * (Predecessor and all symbols in the successor) are
 * in the given alphabet.
 * @tparam SymbolType
 * @param production const Production<SymbolType>&
 * @param alphabet const std::unordered_set<SymbolType>&
 * @return If all symbols are in the alphabet, this function returns true, otherwise, this function returns false.
 */
template <typename SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const std::unordered_set<SymbolType>& alphabet);

/**
 * @description This function verifies that all symbols in the productions successor set are unique.
 * @tparam SymbolType
 * @param production std::unordered_set<Production<SymbolType>>&
 * @return If all successors are unique, this function returns true, otherwise, this function returns false.
 */
template <typename SymbolType>
bool isUniqueProductionSet(const std::unordered_set<Production<SymbolType>>& production);

/**
 * @description This function checks if each symbol in the alphabet has 1 production
 * @tparam SymbolType
 * @param production const std::unordered_set<Production<SymbolType>>&
 * @param alphabet const std::unordered_set<SymbolType>&
 * @return returns a new set of productions
 */
template <typename SymbolType>
std::unordered_set<Production<SymbolType>> isInAlphabet(const std::unordered_set<Production<SymbolType>>& productions, const std::unordered_set<SymbolType>& alphabet);

/**
 * @description This function checks if each symbol in the axiom is in the alphabet
 * @tparam SymbolType
 * @param axiom const std::vector<SymbolType>&
 * @param alphabet const std::unordered_set<SymbolType>&
 * @return returns true if valid, false otherwise
 */
template <typename SymbolType>
bool isValidAxiom(const std::vector<SymbolType>& axiom, const std::unordered_set<SymbolType>& alphabet);
#endif //DATASTRUCTURE_VALIDATION_HPP
