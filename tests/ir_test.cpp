#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"   // library for unit tests
#include "../cpu/ir.h" //class to be tested
using namespace std;

TEST_CASE("IR Test")
{
    Ir instructionReg(0, RAM_PROGRAM_ADDRESS);
    Ram ram0(true);
    instructionReg.get_ram(ram0);

    SECTION("Initialisation TEST")
    {
        instructionReg.get_instruction();
        REQUIRE(instructionReg.op_code == 2);
        REQUIRE(instructionReg.rs1 == 1);
        REQUIRE(instructionReg.rs0 == 2);
        REQUIRE(instructionReg.rd == 3);
    }
    SECTION("get_next_instruction TEST0")
    {
        instructionReg.get_next_instruction();
        REQUIRE(instructionReg.op_code == 3);
        REQUIRE(instructionReg.rs1 == 2);
        REQUIRE(instructionReg.rs0 == 1);
        REQUIRE(instructionReg.rd == 4);

        SECTION("get_next_instruction TEST1")
        {
            instructionReg.get_next_instruction();
            REQUIRE(instructionReg.op_code == 4);
            REQUIRE(instructionReg.rs1 == 1);
            REQUIRE(instructionReg.rs0 == 2);
            REQUIRE(instructionReg.rd == 5);
        }
        SECTION("get_instruction TEST0")
        {
            instructionReg.get_instruction();
            REQUIRE(instructionReg.op_code == 3);
            REQUIRE(instructionReg.rs1 == 2);
            REQUIRE(instructionReg.rs0 == 1);
            REQUIRE(instructionReg.rd == 4);
        }
    }
}