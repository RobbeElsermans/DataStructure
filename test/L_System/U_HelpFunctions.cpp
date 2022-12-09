//
// Created by robbeelsermans on 12/9/22.
//
#include <catch2/catch.hpp>
#include "../../lib/L_System/include/Production.hpp"
#include "../../lib/L_System/include/HelpFunctions.hpp"



TEST_CASE("Validating equality Vector"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    std::vector<char> v1 = {'A', 'C', '-'};
    std::vector<char> v2 = {'A', 'C', '-'};

    CHECK(v != v1);
    CHECK(v1 == v2);
    CHECK(v != v2);
}

TEST_CASE("Test randomness hashFunction")
{
    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create production
    std::vector<char> v1 = {'A', 'C', '-'};
    Production<char> p1 = Production<char> ('B', v1);

    //maak hash functie aan
    std::hash<Production<char>> h;
    //size_t getal = h.operator()(p);
    //std::cout << getal << std::endl;

    CHECK(h.operator()(p) != h.operator()(p1) );
}