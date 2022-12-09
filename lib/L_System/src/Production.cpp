//
// Created by robbeelsermans on 12/5/22.
//

#include "../include/Production.hpp"

template<typename SymbolType>
Production<SymbolType>::Production(SymbolType predecessor, std::vector<SymbolType> successor) {
    Production::predecessor = predecessor;
    Production::successor = successor;
}

template<typename SymbolType>
SymbolType Production<SymbolType>::getPredecessor() {
    return Production::predecessor ;
}

template<typename SymbolType>
std::vector<SymbolType> Production<SymbolType>::getSuccessor() {
    return Production::successor;
}

template class Production<char>;
//template std::vector<char> Production<char>::getSuccessor();