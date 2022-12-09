//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_PRODUCTION_HPP
#define DATASTRUCTURE_PRODUCTION_HPP

#include <string>
#include <vector>
#include <map>

// This class represents a single production.
// A production is a replacement rule, it tells us which symbol
// to look for, and what (sequence of) symbol(s) to replace it with.
// The original symbol is usually called a “predecessor”.
// The (sequence of) symbol(s) is usually called a “successor”.
template <typename SymbolType>
class Production {
public:

    // contructor
    Production(SymbolType predecessor, std::vector<SymbolType> successor);

    //get the key
    SymbolType getPredecessor();

    //get the value
    std::vector<SymbolType> getSuccessor();
    bool operator==(const Production<SymbolType>& str1) const;

private:
    //De replacements rules
    SymbolType predecessor;
    std::vector<SymbolType> successor;

};

#endif //DATASTRUCTURE_PRODUCTION_HPP
