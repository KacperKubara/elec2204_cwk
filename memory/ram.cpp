#include "ram.h"
#include <iostream>

unsigned int Ram::ram[RAM_SIZE] = 
    { // MEMORY DATA - Core Regs(0-4)
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000,
        // MEMORY DATA - Temp Regs(5-15)
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000,
        // MEMORY DATA - Core Regs(16-31)
        0x00000000, 0x00000064, 0x00000001, 0x00000005,
        0x00000004, 0x00000002, 0x000003E8, 0x00000006,
        0x0000000D, 0x0000000F, 0x00000006, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        // PROGRAM DATA
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x0F000000
};

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
void Ram::print_all(void)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        std::cout << std::hex << ram[i] << " ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
}