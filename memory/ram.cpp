#include "ram.h"
#include "../hardcoded.cpp"

Ram::Ram()
{
    int ram[RAM_SIZE] = {}; // initialise array with 0 values
}

Ram::Ram(bool is_hardcoded)
{
    if (is_hardcoded)
    {
        for (int i = 0; i < RAM_SIZE; i++)
        {
            ram[i] = ram_hardcoded[i];
        }
    }

    else
        int ram[RAM_SIZE] = {};
}

Ram::Ram(int new_ram[RAM_SIZE])
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        Ram::ram[i] = new_ram[i];
    }
}

int *Ram::base_address_data(void)
{
    return &ram[RAM_DATA_ADDRESS];
}

int Ram::read(int n)
{
    return ram[n];
}

bool Ram::write(int n, int value)
{
    if (n < RAM_SIZE && n >= 0)
    {
        ram[n] = value;
        return true;
    }
    else
        return false;
}