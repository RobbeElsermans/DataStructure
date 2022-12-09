//
// Created by robbeelsermans on 12/9/22.
//

#ifndef DATASTRUCTURE_HELPFUNCTIONS_HPP
#define DATASTRUCTURE_HELPFUNCTIONS_HPP

#include <unordered_set>
#include "Production.hpp"


namespace std {
    template<typename SymbolType>
    struct hash<Production<SymbolType>> {
    std::size_t operator()(const Production<SymbolType> &production) const noexcept;
};
}
/*
template <class SymbolType>
bool operator== (const std::vector<SymbolType>& v1, const std::vector<SymbolType>& v2);
 */
//iterator
template <typename IteratorType>
Production<char> forwardIterate(IteratorType begin, IteratorType end);

//Ite

#endif //DATASTRUCTURE_HELPFUNCTIONS_HPP
