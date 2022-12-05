//
// Created by robbeelsermans on 12/5/22.
//

#include "LSystem/LSystemInterpreter.h"


template<typename SymbolType>
LSystemInterpreter<SymbolType>::LSystemInterpreter(const std::vector<SymbolType> &axiom,
                                                   const std::unordered_set<Production<SymbolType>> &productions,
                                                   const std::unordered_set<SymbolType> &alphabet) {

}

template<typename SymbolType>
std::vector<SymbolType> LSystemInterpreter<SymbolType>::generate(unsigned long iterations) {
    return std::vector<SymbolType>();
}
