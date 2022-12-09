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
    const std::vector<char> axiom;
    const std::unordered_set<Production<char>> productions;
    const std::unordered_set<char> alphabet;

    LSystemInterpreter<char> lSystemInterpreter = LSystemInterpreter<char>(axiom, productions, alphabet);
}