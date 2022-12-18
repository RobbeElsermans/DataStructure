//
// Created by robbeelsermans on 12/9/22.
//

#ifndef DATASTRUCTURE_HELPFUNCTIONS_HPP
#define DATASTRUCTURE_HELPFUNCTIONS_HPP

#include <unordered_set>
#include "Production.hpp"

namespace std {
    template<typename SymbolType>
    /**
     * Hash override
     * @tparam SymbolType
     */
    struct hash<Production<SymbolType>> {
    std::size_t operator()(const Production<SymbolType> &production) const noexcept;
};
}

#endif //DATASTRUCTURE_HELPFUNCTIONS_HPP
