/*
RAM Specification:
Size: 256 Bytes (64 words)
*/
#include "../configure.h"

class Ram
{
    public:
    // physical memory
    int ram[RAM_SIZE]; // array with 0 values
    
    // default constructor
    Ram();
    // constructor with a new ram data
    Ram(int new_ram[RAM_SIZE]);
    // return base address of RAM
    int *base_address(void);
};