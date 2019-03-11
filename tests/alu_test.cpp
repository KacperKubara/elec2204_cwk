#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"    // library for unit tests
#include "../cpu/alu.h" //class to be tested

using namespace std;

TEST_CASE("ALU Test")
{
    Alu alu;
    SECTION("Op Code Test")
    {
        for (int i = 2; i < 6; i++)
        {
            alu.output_result(i, 5, 3);
            REQUIRE(alu.signal != 0);
        }
    }
    SECTION("Alu Result test")
    {        
        REQUIRE(alu.output_result(2, 5, 3) == 8);
        REQUIRE(alu.output_result(3, 5, 3) == 2);
        REQUIRE(alu.output_result(4, 5, 3) == 15);
        REQUIRE(alu.output_result(5, 5, 3) == 1);
    }
}