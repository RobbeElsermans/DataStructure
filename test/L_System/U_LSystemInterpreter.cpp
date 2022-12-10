//
// Created by robbeelsermans on 12/9/22.
//
#include <catch2/catch.hpp>
//#include "../include/LS.hpp"
#include "../lib/L_System/include/LSystemInterpreter.hpp"
#include "../../lib/L_System/include/Validation.hpp"
#include "../../lib/L_System/include/HelpFunctions.hpp"

TEST_CASE("Check contructor"){

    //LSystemInterpreter define
    const std::vector<char> axiom{'A','B', 'B'};
    const std::unordered_set<Production<char>> productions{
        Production<char>{'A', {'A', 'X','A'}},
        Production<char>{'B', {'B', 'X','B'}},
        Production<char>{'C', {'+', 'X','+'}},
    };
    const std::unordered_set<char> alphabet{'A','B', 'C', 'D', 'E'};



    LSystemInterpreter<char> lSystemInterpreter = LSystemInterpreter<char>(axiom, productions, alphabet);


}