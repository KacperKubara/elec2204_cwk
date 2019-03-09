#include "configure.h"
#include "pc.h"

pc::pc(int count){
    counter = count;
}

int pc::increment(){
   return counter += 4;
}