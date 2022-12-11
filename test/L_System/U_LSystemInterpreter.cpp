//
// Created by robbeelsermans on 12/9/22.
//
#include <catch2/catch.hpp>
//#include "../include/LS.hpp"
#include "../lib/L_System/include/LSystemInterpreter.hpp"
#include "../../lib/L_System/include/Validation.hpp"
#include "../../lib/L_System/include/HelpFunctions.hpp"

TEST_CASE("Check constructor when valid"){

    //LSystemInterpreter define
    const std::vector<char> axiom{'A','B', 'B'};
    const std::unordered_set<Production<char>> productions{
        Production<char>{'A', {'A', 'X','A'}},
        Production<char>{'B', {'B', 'X','B'}},
        Production<char>{'C', {'+', 'X','+'}},
    };
    const std::unordered_set<char> alphabet{'A','B', 'C', 'D', 'E', 'X', '+'};

    CHECK_NOTHROW(LSystemInterpreter<char>(axiom, productions, alphabet));
}

//TODO check ook ofdat axiom in alphabet zit?
TEST_CASE("Check constructor when invalid axiom"){

    //LSystemInterpreter define
    const std::vector<char> axiom{'A','Q', 'B'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'A', 'X','A'}},
            Production<char>{'B', {'B', 'X','B'}},
            Production<char>{'C', {'+', 'X','+'}},
    };
    const std::unordered_set<char> alphabet{'A','B', 'C', 'D', 'E','+', 'X'};

    CHECK_THROWS(LSystemInterpreter<char>(axiom, productions, alphabet));
}

TEST_CASE("Check constructor when double successor"){

    //LSystemInterpreter define
    const std::vector<char> axiom{'A','Q', 'B'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'A', 'X','A'}},
            Production<char>{'B', {'B', 'X','B'}},
            Production<char>{'C', {'B', 'X','B'}},
    };
    const std::unordered_set<char> alphabet{'A','B', 'C', 'D', 'E','Q'};

    CHECK_THROWS(LSystemInterpreter<char>(axiom, productions, alphabet));
}

TEST_CASE("Check constructor when double predecessor"){

    //LSystemInterpreter define
    const std::vector<char> axiom{'A','Q', 'B'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'A', 'X','A'}},
            Production<char>{'B', {'B', 'X','B'}},
            Production<char>{'B', {'B', 'X','-'}},
    };
    const std::unordered_set<char> alphabet{'A','B', 'C', 'D', 'E', 'X', '-'};

    CHECK_THROWS(LSystemInterpreter<char>(axiom, productions, alphabet));
}

TEST_CASE("Check generator with 1 iteration"){
    const std::vector<char> axiom{'A', 'B'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'A', 'B'}},
            Production<char>{'B', {'A'}},
    };

    const std::unordered_set<char> alphabet{'A','B'};

    std::vector<char> getVector;

    try{
        LSystemInterpreter<char> sys = LSystemInterpreter<char>(axiom, productions, alphabet);
        getVector = sys.generate(1);
    }
    catch(const std::exception& e) {
        CHECK(false);
    }

    //It should give us a vector of 'ABA'
    std::vector<char> checkVector{'A', 'B','A'};

    CHECK(checkVector == getVector);
}

TEST_CASE("Check generator with 2 iteration"){
    const std::vector<char> axiom{'A', 'B'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'A', 'B'}},
            Production<char>{'B', {'A'}},
    };

    const std::unordered_set<char> alphabet{'A','B'};

    std::vector<char> getVector;

    try{
        LSystemInterpreter<char> sys = LSystemInterpreter<char>(axiom, productions, alphabet);
        getVector = sys.generate(2);
    }
    catch(const std::exception& e) {
        CHECK(false);
    }

    //It should give us a vector of 'ABA' with 1 iteration
    //It should give us a vector of 'ABAAB' with 2 iteration
    std::vector<char> checkVector{'A', 'B','A','A', 'B'};

    CHECK(checkVector == getVector);
}