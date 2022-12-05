//
// Created by robbe on 5/12/22.
//

#include "../include/HashFunction.h"

template<typename SymbolType>
size_t HashFunction<SymbolType>::operator()(const Production<SymbolType> production) {
    Production<SymbolType> p = production;

    size_t id = 0;

    for(SymbolType val : p.getSuccessor()){
        id += p.getPredecessor() * val;
    }

    return (id);
}

template class HashFunction<char>;