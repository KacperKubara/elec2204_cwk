#include "../configure.h"
#include "../memory/ram.h"

class Pc
{
  public:
    // program counter
    int counter;
    // base_address of RAM
    int base_address;

    // constructor
    Pc(int count, int base_address);

    // increments the counter
    int increment(void);
    // gets counter
    int get_counter(void);

    // ram constructor
    Ram ram;   
};