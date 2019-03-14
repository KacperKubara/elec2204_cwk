#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"   // library for unit tests
#include "../cpu/ir.h" //class to be tested
using namespace std;

TEST_CASE("IR Test")
{
    Ir instructionReg(0, RAM_PROGRAM_ADDRESS);
    Ram ram0;
    ram0.write(RAM_PROGRAM_ADDRESS, 0x02010203);
    ram0.write(RAM_PROGRAM_ADDRESS, 0x03020104);
    ram0.write(RAM_PROGRAM_ADDRESS, 0x04020104);
    ram0.write(RAM_PROGRAM_ADDRESS, 0x04010205);
    ram0.write(RAM_PROGRAM_ADDRESS, 0x04010205);

    SECTION("Initialisation TEST")
    {
        instructionReg.get_instruction();
        REQUIRE(instructionReg.op_code == 4);
        REQUIRE(instructionReg.rs1 == 1);
        REQUIRE(instructionReg.rs0 == 2);
        REQUIRE(instructionReg.rd == 5);
    }
    SECTION("get_next_instruction TEST0")
    {
        instructionReg.get_next_instruction();
        REQUIRE(instructionReg.op_code == 0);
        REQUIRE(instructionReg.rs1 == 0);
        REQUIRE(instructionReg.rs0 == 0);
        REQUIRE(instructionReg.rd == 0);

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