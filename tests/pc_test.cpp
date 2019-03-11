#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() 

#include "catch.hpp" // library for unit tests
#include "../cpu/pc.h" //class to be tested
#include "../configure.h"

using namespace std;

Ram ram0(true);
TEST_CASE("PC Test"){
    Pc programCounter(5, RAM_PROGRAM_ADDRESS);
    programCounter.get_ram(ram0);
    SECTION("Counter Test 0"){
        REQUIRE(programCounter.get_counter() == 5 + RAM_PROGRAM_ADDRESS);
    }
    SECTION("Counter Test 1"){
        programCounter.increment();
        REQUIRE(programCounter.get_counter() == 6 + RAM_PROGRAM_ADDRESS);
    }
}