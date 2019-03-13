#include "pc.h"
#include <iostream>
Pc::Pc(int count, int base_address) : ram(true)
{
    counter = count + base_address;
    ram.write(PC_ADDRESS, counter);
}

int Pc::increment(void)
{
    counter = ram.read(0);
    if (counter >= RAM_PROGRAM_ADDRESS && counter < RAM_SIZE)
    {
        counter++;
        ram.write(0, counter);
        return ram.read(0);
    }
    else
    {
        ram.write(0, base_address);
        return ram.read(0);
    }
}

int Pc::get_counter(void)
{
    return ram.read(0);
}
void Pc::print_all(void)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        std::cout << std::hex << ram.read(i) << " ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
}