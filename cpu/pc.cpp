#include "pc.h"

Pc::Pc(int count, int base_address){
    counter = count + base_address;
}

int Pc::increment(){
   return counter += 4;
}