//
// Created by robbe on 5/12/22.
//

#include "catch2/catch.hpp"
#include <iostream>
#include "../../../lib/L_System/include/Validation.hpp"
#include "../../../lib/L_System/include/HelpFunctions.hpp"

TEST_CASE("Test simple Validation True"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create alphabet
    std::unordered_set<char> us;
    us.insert('A');
    us.insert('C');
    us.insert('+');

    CHECK(isValidProduction<char>(p, us));
}

TEST_CASE("Test simple Validation False successors"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create alphabet
    std::unordered_set<char> us;
    us.insert('A');
    us.insert('C');

    CHECK_FALSE(isValidProduction<char>(p, us));
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

    CHECK_FALSE(isValidProduction<char>(p, us));
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

TEST_CASE("Validating dis unique successor"){
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

    CHECK(b == false);
}

TEST_CASE("Test isInAlphabet 0 added"){
    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);
    std::unordered_set<Production<char>> productions = {p};

    //create alphabet
    std::unordered_set<char> alphabet = {'A'};

    std::unordered_set<Production<char>> recieveProductions = isInAlphabet(productions,alphabet);

    CHECK(recieveProductions.size() == productions.size());
}

TEST_CASE("Test isInAlphabet 1 added"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);
    std::unordered_set<Production<char>> productions = {p};
    Production<char> addedP = Production<char> ('b', std::vector<char>{'B'});

    //create alphabet
    std::unordered_set<char> alphabet = {'A', 'B'};

    std::unordered_set<Production<char>> recieveProductions = isInAlphabet(productions,alphabet);

    //check the size
    CHECK(recieveProductions.size() == productions.size()+1);

    //check the content
    for(Production<char> prod : recieveProductions){
        if(prod.getPredecessor() == addedP.getPredecessor() && prod.getSuccessor() == addedP.getSuccessor())
            CHECK(true);
    }
}

TEST_CASE("Test isInAlphabet 2 added"){

    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);
    std::unordered_set<Production<char>> productions = {p};
    Production<char> addedP1 = Production<char> ('B', std::vector<char>{'B'});
    Production<char> addedP2 = Production<char> ('C', std::vector<char>{'C'});

    //create alphabet
    std::unordered_set<char> alphabet = {'A', 'B', 'C'};

    std::unordered_set<Production<char>> recieveProductions = isInAlphabet(productions,alphabet);

    CHECK(recieveProductions.size() == productions.size()+2);
    if(recieveProductions.find(addedP1) != recieveProductions.end()){
        CHECK(true);
    }
    else{
        CHECK(false);
    }
    if(recieveProductions.find(addedP2) != recieveProductions.end()){
        CHECK(true);
    }
    else{
        CHECK(false);
    }
}

TEST_CASE("Validating good axiom"){
    //create axiom
    std::vector<char> axiom = {'A', 'C', '+'};
    std::unordered_set<char> alphabet = {'A', 'C', '+'};

    bool b = isValidAxiom(axiom, alphabet);

    CHECK(b == true);
}

TEST_CASE("Validating bad axiom"){
    //create axiom
    std::vector<char> axiom = {'A', 'X', '+'};
    std::unordered_set<char> alphabet = {'A', 'C', '+'};

    bool b = isValidAxiom(axiom, alphabet);

    CHECK(b == false);
}
