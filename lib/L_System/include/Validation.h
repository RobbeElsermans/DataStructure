//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_VALIDATION_H
#define DATASTRUCTURE_VALIDATION_H

#include <unordered_set>
#include "Production.h"

// This function verifies that all symbols in the production
// (Predecessor and all symbols in the successor) are
// in the given alphabet.
// If all symbols are in the alphabet, this function returns true,
// otherwise, this function returns false.
template <typename SymbolType>
bool isValidProduction(const Production<SymbolType>& production, const std::unordered_set<SymbolType>& alphabet);

#endif //DATASTRUCTURE_VALIDATION_H
