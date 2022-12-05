//
// Created by robbe on 5/12/22.
//
#include "catch2/catch.hpp"
#include "../../lib/L_System/include/Production.h"
#include "../../lib/L_System/include/HashFunction.h"

TEST_CASE("Test randomness hashFunction")
{
    //create production
    std::vector<char> v = {'A', 'C', '+'};
    Production<char> p = Production<char> ('A', v);

    //create production
    std::vector<char> v1 = {'A', 'C', '-'};
    Production<char> p1 = Production<char> ('A', v1);

    HashFunction<char> hashFunction = HashFunction<char>();

    CHECK(hashFunction.operator()(p) != hashFunction.operator()(p1) );
}
