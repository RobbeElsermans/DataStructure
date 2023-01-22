//
// Created by robbeelsermans on 12/5/22.
//
#include "catch2/catch.hpp"
#include "../../../lib/L_System/include/Production.hpp"

TEST_CASE("test the constructor and get functions"){
    //Create a Production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    CHECK(p.getPredecessor() == 'A');

    for (int i = 0; i < (int)p.getSuccessor().size(); ++i) {
        CHECK(p.getSuccessor()[i] == v[i]);
    }
}