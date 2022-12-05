//
// Created by robbe on 5/12/22.
//

#ifndef DATASTRUCTURE_HASHFUNCTION_H
#define DATASTRUCTURE_HASHFUNCTION_H

#include "Production.h"

// class for hash function

template <typename SymbolType>
class HashFunction {
public:
    size_t operator()(const Production<SymbolType> production);
};


#endif //DATASTRUCTURE_HASHFUNCTION_H
