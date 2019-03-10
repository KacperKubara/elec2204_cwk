#include "pc.h"

Pc::Pc(int count, int base_address){
    counter = count + base_address;
}

int Pc::increment(void){
   return counter += 1;
}

int Pc::get_counter(void)
{
    return counter;
}