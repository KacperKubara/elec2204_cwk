#include "../configure.h"
#include "pc.h"
#include "../memory/ram.h"

class Ir
{
  public:
    // ram constructor
    Ram ram;
    // fetched op code
    int op_code;
    // source Register rs0
    int rs0;
    // source Register rs1
    int rs1;
    // destination Register rd
    int rd;


    // constructor
    Ir(int count, int base_address);
    // get ram object by refernce
    void get_ram(Ram &ram_object);
    // increment pc and get new instruction
    void get_next_instruction(void);
    // get instruction
    void get_instruction(void);
    // update op code
    void set_op(int reg_content);
    // update reg1 and reg2
    void set_regs(int reg_content);

    // connect Pc to Ir
    Pc programCounter;
};