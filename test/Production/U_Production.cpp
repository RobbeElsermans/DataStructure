//
// Created by robbeelsermans on 12/5/22.
//
#include <catch2/catch.hpp>
#include "LSystem/Production.h"

TEST_CASE("test de constructor"){
    //Create a Production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    CHECK(p.getPredecessor() == 'A');

    for (int i = 0; i < p.getSuccessor().size(); ++i) {
        CHECK(p.getSuccessor()[i] == v[i]);
    }
}