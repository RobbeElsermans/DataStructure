//
// Created by robbeelsermans on 12/5/22.
//

#ifndef DATASTRUCTURE_PRODUCTION_HPP
#define DATASTRUCTURE_PRODUCTION_HPP

#include <string>
#include <vector>
#include <map>

/**
 * This class represents a single production.
 * @tparam SymbolType
 * @description
 * A production is a replacement rule, it tells us which symbol
 * to look for, and what (sequence of) symbol(s) to replace it with.
 * The original symbol is usually called a “predecessor”.
 * The (sequence of) symbol(s) is usually called a “successor”.
 */
template <typename SymbolType>
class Production {
public:


    /**
     * Empty constructor for returning an empty object (initialize)
     */
    Production();


    /**
     * The actual creat constructor that needs an predecessor an 1 or many successors
     * @param predecessor
     * @param successor
     */
    Production(SymbolType predecessor, std::vector<SymbolType> successor);


    /**
     * get method for the predecessor
     * @return SymbolType predecessor
     */
    SymbolType getPredecessor();

    /**
     * get method for the successors
     * @return SymbolType successors
     */
    std::vector<SymbolType> getSuccessor();

    /**
     * define the equality operator between Productions classes
     * @param str1
     * @return bool true if equal, false if not
     */
    bool operator==(const Production<SymbolType>& str1) const;

private:
    /**
     * The replacement argument predecessor
     */
    SymbolType predecessor;

    /**
     * The replacer objects successors
     */
    std::vector<SymbolType> successor;
};

#endif //DATASTRUCTURE_PRODUCTION_HPP
