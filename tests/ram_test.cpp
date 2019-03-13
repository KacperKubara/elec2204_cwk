#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()

#include "catch.hpp"       // library for unit tests
#include "../memory/ram.h" //class to be tested

using namespace std;

TEST_CASE("RAM Test")
{
    SECTION("Hardcoded RAM Test")
    {
        Ram ram0;
        SECTION("Hardcoded RAM Read Test")
        {
            REQUIRE(ram0.read(0) == 0);
            REQUIRE(ram0.read(8) == 0);
            REQUIRE(ram0.read(9) == 0);
        }
        SECTION("Hardcoded RAM Write Test")
        {
            REQUIRE(ram0.write(0, 0xDEADBEEF) == true);

            SECTION("Hardcoded RAM Read after Write Test")
            {
                REQUIRE(ram0.read(0) == 0xDEADBEEF);
            }
        }
    }
    SECTION("Default RAM Test")
    {
        Ram ram1;
        SECTION("Default RAM Read Test")
        {
            REQUIRE(ram1.read(0) == 0xDEADBEEF);
            REQUIRE(ram1.read(8) == 0);
            REQUIRE(ram1.read(9) == 0);
        }
        SECTION("Default RAM Write Test")
        {
            REQUIRE(ram1.write(0, 0xBEEFBEEF) == true);

            SECTION("Default RAM Read after Write Test")
            {
                REQUIRE(ram1.read(0) == 0xBEEFBEEF);
            }
        }
    }
}