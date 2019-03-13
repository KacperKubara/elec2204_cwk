#include "../configure.h"
#include "ir.h"
#include "alu.h"
class Cpu
{
    public:
    // alu computation result
    int alu_result;
    // flag to determine if execute_cycle is run for the 1st time
    bool first_run;

    // constructor
    Cpu(int count, int base_address);
    
    // execute cycle
    void execute_cycle(void);
    // execute instruction
    void execute_instruction(void);
    // increment opcode and update regs
    void fetch(void); 
    
    // connect IR with PC to Cpu
    Ir ir;
    // connect ALU to Cpu
    Alu alu;
    // connect RAM to Cpu
    Ram ram;
};