#include "../configure.h"
#include "pc.h"

class Ir
{
    public:
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
    // increment pc and sets new instruction
    void set_next_instruction(void);
    // sets instruction
    void set_instruction(void);
    // update op code
    void set_op(int reg_content);
    // update reg1 and reg2
    void set_regs(int reg_content);

    private:
    // connect Pc to Ir
    Pc programCounter;

};