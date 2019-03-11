#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() 

#include "catch.hpp" // library for unit tests
#include "../cpu/cpu.h" //class to be tested

using namespace std;

TEST_CASE("CPU Test"){
    Pc programCounter(5, 0);
    SECTION("CPU Test 0"){
        REQUIRE(programCounter.get_counter() == 5);
    }
}