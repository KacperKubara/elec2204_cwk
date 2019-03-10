#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"     // library for unit tests
#include "ir.h" //class to be tested

using namespace std;

TEST_CASE("IR Test")
{
    Ir instructionReg(0, RAM_PROGRAM_ADDRESS);
    SECTION("Initialisation TEST")
    {
        REQUIRE(instructionReg.op_code == 0);
        REQUIRE(instructionReg.reg1 == 0xFFF);
        REQUIRE(instructionReg.reg2 == 0xAAA);
    }
    SECTION("set_next_instruction TEST0")
    {
        instructionReg.set_next_instruction();
        REQUIRE(instructionReg.op_code == 1);
        REQUIRE(instructionReg.reg1 == 0xAAA);
        REQUIRE(instructionReg.reg2 == 0xFFF);

        SECTION("set_next_instruciton TEST1")
        {
            instructionReg.set_next_instruction();
            REQUIRE(instructionReg.op_code == 2);
            REQUIRE(instructionReg.reg1 == 0xDDD);
            REQUIRE(instructionReg.reg2 == 0xBBB);           
        }
    }
}