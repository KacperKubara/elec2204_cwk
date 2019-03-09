#include "ram.h"

Ram::Ram()
{
    int ram[RAM_SIZE] = {}; // initialise array with 0 values
}

Ram::Ram(int new_ram[RAM_SIZE])
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        Ram::ram[i] = new_ram[i];
    }
}

int * Ram::base_address(void)
{
    return &ram[0];
}