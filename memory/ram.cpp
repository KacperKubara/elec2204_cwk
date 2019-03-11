#include "ram.h"
#include "../hardcoded.cpp"

Ram::Ram()
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        ram[i] = 0;
    }
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
        for (int i = 0; i < RAM_SIZE; i++)
        {
            ram[i] = 0;
        }
}

Ram::Ram(unsigned int new_ram[RAM_SIZE])
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        ram[i] = new_ram[i];
    }
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