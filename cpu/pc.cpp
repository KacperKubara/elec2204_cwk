#include "pc.h"

Pc::Pc(int count, int base_address)
{
    counter = count + base_address;
}

int Pc::increment(void)
{
    if (counter >= RAM_PROGRAM_ADDRESS && counter < RAM_SIZE)
        return counter += 1;
    else
    {
        counter = base_address;
        return counter;
    }
}

int Pc::get_counter(void)
{
    return counter;
}