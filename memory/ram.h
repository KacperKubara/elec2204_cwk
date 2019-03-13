/*
RAM Specification:
Size: 256 Bytes (64 words)
*/
#include "../configure.h"

class Ram
{
    public:
    // physical memory with preupload program and data
    static unsigned int ram[RAM_SIZE]; 

    // return the value of the memory cell
    int read(int n); 
    // debug function
    void print_all(void);
    // return true if write is successfull  
    bool write(int n, int value); 
};