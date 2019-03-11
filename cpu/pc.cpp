#include "pc.h"

Pc::Pc(int count, int base_address)
{
    counter = count + base_address;
}

void Pc::get_ram(Ram &ram_object)
{
    ram = ram_object;
    ram.write(0, counter);
}
int Pc::increment(void)
{   
    counter = ram.read(0);
    if (counter >= RAM_PROGRAM_ADDRESS && counter < RAM_SIZE){
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