//
// Created by robbe on 5/12/22.
//

#include <catch2/catch.hpp>
#include <iostream>
#include "../../lib/L_System/include/Validation.hpp"
#include "../../lib/L_System/include/HelpFunctions.hpp"

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

    CHECK_THROWS(isValidProduction<char>(p, us));
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

    CHECK_THROWS(isValidProduction<char>(p, us));
}

TEST_CASE("Validating Unique successor"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    const Production<char> p = Production<char> ('A', v);

    std::vector<char> v1 = {'A', 'C', '-'};
    const Production<char> p1 = Production<char> ('B', v1);

    std::vector<char> v2 = {'A', 'C', '*'};
    const Production<char> p2 = Production<char> ('C', v2);

    std::unordered_set<Production<char>> usProductions;
    usProductions.insert(p);
    usProductions.insert(p1);
    usProductions.insert(p2);

    bool b = isUniqueProductionSet(usProductions);
    //std::cout << b << std::endl;

   CHECK(b == true);
}

TEST_CASE("Validating disUnique successor"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    const Production<char> p = Production<char> ('A', v);

    std::vector<char> v1 = {'A', 'C', '-'};
    const Production<char> p1 = Production<char> ('B', v1);

    std::vector<char> v2 = {'A', 'C', '-'};
    const Production<char> p2 = Production<char> ('C', v2);

    std::unordered_set<Production<char>> usProductions;
    usProductions.insert(p);
    usProductions.insert(p1);
    usProductions.insert(p2);

    bool b = isUniqueProductionSet(usProductions);
    //std::cout << b << std::endl;

    CHECK(b == false);
}

TEST_CASE("Validating Unique predecessor"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    const Production<char> p = Production<char> ('A', v);

    std::vector<char> v1 = {'A', 'C', '-'};
    const Production<char> p1 = Production<char> ('B', v1);

    std::vector<char> v2 = {'A', 'C', '*'};
    const Production<char> p2 = Production<char> ('C', v2);

    std::unordered_set<Production<char>> usProductions;
    usProductions.insert(p);
    usProductions.insert(p1);
    usProductions.insert(p2);

    bool b = isUniqueProductionSet(usProductions);
    //std::cout << b << std::endl;

    CHECK(b == true);
}

TEST_CASE("Validating disUnique predecessor"){
    //create productions
    std::vector<char> v = {'A', 'C', '+'};
    const Production<char> p = Production<char> ('A', v);

    std::vector<char> v1 = {'A', 'C', '-'};
    const Production<char> p1 = Production<char> ('B', v1);

    std::vector<char> v2 = {'A', 'C', '*'};
    const Production<char> p2 = Production<char> ('B', v2);

    std::unordered_set<Production<char>> usProductions;
    usProductions.insert(p);
    usProductions.insert(p1);
    usProductions.insert(p2);
    ;
    bool b = isUniqueProductionSet(usProductions);
    //std::cout << b << std::endl;

    CHECK(b == false);
}