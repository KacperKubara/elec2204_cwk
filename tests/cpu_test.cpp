#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"    // library for unit tests
#include "../cpu/cpu.h" //class to be tested
#include "../configure.h"

using namespace std;

TEST_CASE("CPU Test")
{
    Cpu cpu0(0, RAM_PROGRAM_ADDRESS);
    SECTION("CPU initialisation test")
    {
        // Alu test
        REQUIRE(cpu0.alu_result == 0);
        REQUIRE(cpu0.alu.signal == 0);

        // IR - Ram test
        REQUIRE(cpu0.ir.ram.read(8) == 0xDEADBEEF);

        // Ir - programCounter test
        REQUIRE(cpu0.ir.programCounter.get_counter() == RAM_PROGRAM_ADDRESS);
        REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS);

        SECTION("CPU Execute Cycle Test")
        {
            cpu0.execute_cycle();
            REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS);
            REQUIRE(cpu0.ir.op_code == 0x00);
            REQUIRE(cpu0.ir.rs0 == 0x01);
            REQUIRE(cpu0.ir.rs1 == 0x02);
            REQUIRE(cpu0.ir.rd == 0x03);
            SECTION("CPU Execute Cycle Test 2")
            {
                cpu0.execute_cycle();
                REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS + 1);
                REQUIRE(cpu0.ir.op_code == 0x01);
                REQUIRE(cpu0.ir.rs0 == 0x02);
                REQUIRE(cpu0.ir.rs1 == 0x03);
                REQUIRE(cpu0.ir.rd == 0x04);
            }
        }
    }
}