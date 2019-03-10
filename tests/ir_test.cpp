#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"   // library for unit tests
#include "../cpu/ir.h" //class to be tested

using namespace std;

TEST_CASE("IR Test")
{
    Ir instructionReg(0, RAM_PROGRAM_ADDRESS);
    SECTION("Initialisation TEST")
    {
        REQUIRE(instructionReg.op_code == 0);
        REQUIRE(instructionReg.rs0 == 1);
        REQUIRE(instructionReg.rs1 == 2);
        REQUIRE(instructionReg.rd  == 3);
    }
    SECTION("set_next_instruction TEST0")
    {
        instructionReg.set_next_instruction();
        REQUIRE(instructionReg.op_code == 1);
        REQUIRE(instructionReg.rs0 == 2);
        REQUIRE(instructionReg.rs1 == 3);
        REQUIRE(instructionReg.rd  == 4);

        SECTION("set_next_instruction TEST1")
        {
            instructionReg.set_next_instruction();
            REQUIRE(instructionReg.op_code == 2);
            REQUIRE(instructionReg.rs0 == 3);
            REQUIRE(instructionReg.rs1 == 4);
            REQUIRE(instructionReg.rd  == 5);
        }
        SECTION("set_instruction TEST0")
        {
            instructionReg.set_instruction();
            REQUIRE(instructionReg.op_code == 1);
            REQUIRE(instructionReg.rs0 == 2);
            REQUIRE(instructionReg.rs1 == 3);
            REQUIRE(instructionReg.rd  == 4);
        }
    }
}