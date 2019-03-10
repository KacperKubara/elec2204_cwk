/*
RAM Specification:
Size: 256 Bytes (64 words)
*/
#include "../configure.h"

class Ram
{
    public:
    // physical memory
    static int ram[RAM_SIZE]; // array with 0 values
    
    // default constructor
    Ram();
    // constructor with a new ram content
    Ram(int new_ram[RAM_SIZE]);
    // return the program base address of RAM
    int *base_address_program(void);
    // return the data base address of RAM
    int *base_address_data(void);
    // returns the value the memory cell
    int read(int n); 
    // returns true if write is successfull  
    bool write(int n, int value); 
};