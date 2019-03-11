#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() 

#include "catch.hpp" // library for unit tests
#include "../cpu/cpu.h" //class to be tested
#include "../configure.h"

using namespace std;

TEST_CASE("CPU Test"){
    Cpu cpu0(0, RAM_PROGRAM_ADDRESS);
    SECTION("CPU Test 0"){
        REQUIRE(cpu0.alu_result == 0);
    }
}