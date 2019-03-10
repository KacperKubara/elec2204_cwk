#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() 

#include "catch.hpp" // library for unit tests
#include "../cpu/pc.cpp" //class to be tested
#include <iostream>

using namespace std;

TEST_CASE("PC Test"){
    Pc programCounter(5, 0);
    SECTION("Counter Test 0"){
        REQUIRE(programCounter.get_counter() == 5);
    }
    SECTION("Counter Test 1"){
        programCounter.increment();
        REQUIRE(programCounter.get_counter() == 6);
    }
}