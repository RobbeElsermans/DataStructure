//
// Created by robbe on 5/12/22.
//

#include <catch2/catch.hpp>
#include <iostream>
#include "../../lib/L_System/include/Validation.h"

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