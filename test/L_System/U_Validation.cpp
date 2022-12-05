//
// Created by robbe on 5/12/22.
//

#include <catch2/catch.hpp>
#include <iostream>
#include "../../lib/L_System/include/Validation.h"
#include "../../lib/L_System/include/HashFunction.h"

TEST_CASE("Test simple Validation True"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create alphabet
    std::unordered_set<char> us;
    us.insert('A');
    us.insert('C');
    us.insert('+');

    CHECK(isValidProduction<char>(p, us) == true);
}

TEST_CASE("Test simple Validation False successors"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create alphabet
    std::unordered_set<char> us;
    us.insert('A');
    us.insert('C');

    CHECK(isValidProduction<char>(p, us) == false);
}

TEST_CASE("Test simple Validation False predecessor"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('Q', v);

    //create alphabet
    std::unordered_set<char> us;
    us.insert('A');
    us.insert('C');
    us.insert('+');

    CHECK(isValidProduction<char>(p, us) == false);
}

TEST_CASE("Validating Unique Productions"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    const Production<char> p = Production<char> ('A', v);

    std::vector<char> v1 = {'A', 'C', '-'};
    const Production<char> p1 = Production<char> ('B', v);

    std::vector<char> v2 = {'B', 'C', '-'};
    const Production<char> p2 = Production<char> ('C', v);

    std::unordered_set<Production<char>, HashFunction<char>> usProductions;
//TODO vergekijk met Lab... waarin we ook unordered_set gebruiken
//    usProductions.insert(p, HashFunction<char>());
}