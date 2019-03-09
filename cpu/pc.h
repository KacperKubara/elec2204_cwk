#include "../configure.h"

class Pc
{
    public:
    
    // program counter
    int counter;
    int base_address; // base_address of RAM

    // constructor
    Pc(int count, int base_address);
    // incrementer
    int increment(void);
};