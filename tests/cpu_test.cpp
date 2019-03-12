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

        // Ram test
        REQUIRE(cpu0.ram.read(2) == 7);
        REQUIRE(cpu0.ram.write(3, 10) == true);       
        REQUIRE(cpu0.ram.read(3) == 10);
        // IR - Ram, PC - RAM test again
        REQUIRE(cpu0.ir.ram.read(3) == 10);
        REQUIRE(cpu0.ir.programCounter.ram.read(8) == 0xDEADBEEF);

        SECTION("CPU Execute Cycle 1 Test - Add")
        {
            cpu0.execute_cycle();
            REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS);
            REQUIRE(cpu0.ir.op_code == 0x02);
            REQUIRE(cpu0.ir.rs1 == 0x01);
            REQUIRE(cpu0.ir.rs0 == 0x02);
            REQUIRE(cpu0.ir.rd == 0x03);
            REQUIRE(cpu0.ram.read(3) == 10);
            SECTION("CPU Execute Cycle 2 Test - Subtract")
            {
                cpu0.execute_cycle();
                REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS + 1);
                REQUIRE(cpu0.ir.op_code == 0x03);
                REQUIRE(cpu0.ir.rs1 == 0x02);
                REQUIRE(cpu0.ir.rs0 == 0x01);
                REQUIRE(cpu0.ir.rd == 0x04);
                REQUIRE(cpu0.ram.read(4) == 4);
                SECTION("CPU Execute Cycle 3 - Multiply")
                {
                    cpu0.execute_cycle();
                    REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS + 2);
                    REQUIRE(cpu0.ir.op_code == 0x04);
                    REQUIRE(cpu0.ir.rs1 == 0x01);
                    REQUIRE(cpu0.ir.rs0 == 0x02);
                    REQUIRE(cpu0.ir.rd == 0x05);
                    REQUIRE(cpu0.ram.read(5) == 21);
                    SECTION("CPU Execute Cycle 4 Test - Divide")
                    {
                        cpu0.execute_cycle();
                        REQUIRE(cpu0.ir.programCounter.counter == RAM_PROGRAM_ADDRESS + 3);
                        REQUIRE(cpu0.ir.op_code == 0x05);
                        REQUIRE(cpu0.ir.rs1 == 0x02);
                        REQUIRE(cpu0.ir.rs0 == 0x01);
                        REQUIRE(cpu0.ir.rd == 0x06);
                        REQUIRE(cpu0.ram.read(6) == 2);
                    }
                }
            }
        }
    }
}