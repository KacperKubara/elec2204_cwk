#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"       // library for unit tests
#include "../memory/ram.h" //class to be tested

using namespace std;

TEST_CASE("RAM Test")
{
    SECTION("Hardcoded RAM Test")
    {
        Ram ram0(true);
        SECTION("Hardcoded RAM Read Test")
        {
            REQUIRE(ram0.read(0) == 0);
            REQUIRE(ram0.read(8) == 0xDEADBEEF);
            REQUIRE(ram0.read(9) == 0xBEEFDEAD);
        }
        SECTION("Hardcoded RAM Write Test")
        {
            REQUIRE(ram0.write(0, 0xDEADBEEF) == true);

            SECTION("Hardcoded RAM Read after Write Test")
            {
                REQUIRE(ram0.read(0) == 0xDEADBEEF);
            }
        }
        SECTION("Hardcoded RAM Base Address Test")
        {
            REQUIRE(ram0.base_address_data() != 0);
        }
    }
    SECTION("Default RAM Test")
    {
        Ram ram1;
        SECTION("Default RAM Read Test")
        {
            REQUIRE(ram1.read(0) == 0);
            REQUIRE(ram1.read(8) == 0);
            REQUIRE(ram1.read(9) == 0);
        }
        SECTION("Default RAM Write Test")
        {
            REQUIRE(ram1.write(0, 0xDEADBEEF) == true);

            SECTION("Default RAM Read after Write Test")
            {
                REQUIRE(ram1.read(0) == 0xDEADBEEF);
            }
        }
        SECTION("0 RAM Base Address Test")
        {
            REQUIRE(ram1.base_address_data() != 0);
        }
    }
        SECTION("False RAM Test")
    {
        Ram ram2(false);
        SECTION("False RAM Read Test")
        {
            REQUIRE(ram2.read(0) == 0);
            REQUIRE(ram2.read(8) == 0);
            REQUIRE(ram2.read(9) == 0);
        }
        SECTION("False RAM Write Test")
        {
            REQUIRE(ram2.write(0, 0xDEADBEEF) == true);

            SECTION("False RAM Read after Write Test")
            {
                REQUIRE(ram2.read(0) == 0xDEADBEEF);
            }
        }
        SECTION("0 RAM Base Address Test")
        {
            REQUIRE(ram2.base_address_data() != 0);
        }
    }
}