//
// Created by robbeelsermans on 12/5/22.
//

#include <iostream>
#include "../include/Validation.h"


template<typename SymbolType>
bool isValidProduction(const Production<SymbolType> &production, const std::unordered_set<SymbolType> &alphabet) {
    //check if all values are in the alphabet
//check if all values are in the alphabet
    //L_System<char> p = production;
    //test itteration
    Production<SymbolType> p = production;


    //reference: https://thispointer.com/c-11-unordered_set-basic-usage-example/
    /*
    for (SymbolType value: alphabet) {
        std::cout << value << std::endl;
    }
     */
    //reference: https://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset
    const bool isInPredecessor = alphabet.find(p.getPredecessor()) != alphabet.end();

    bool isInSuccessor = false;
    for (SymbolType value: p.getSuccessor()) {
        if (alphabet.find(value) != alphabet.end()) {
            isInSuccessor = true;
        }
        else{
            //Als er 1 fout in zit, stoppen want ze moeten allen in het alphabet voorkomen.
            isInSuccessor = false;
            break;
        }
    }

    return isInPredecessor && isInSuccessor;
}


//Explicit declaration
template bool isValidProduction(const Production<char> &production, const std::unordered_set<char> &alphabet);

/*{
    //check if all values are in the alphabet
    //L_System<char> p = production;
    //test itteration
    for(char value : alphabet){
        std::cout << value << std::endl;
    }
    return false;
}
 */