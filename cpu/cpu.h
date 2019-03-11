#include "../configure.h"
#include "ir.h"
#include "alu.h"
class Cpu
{
    public:
    // define clock Speed
    const int clock_freq = CLOCK_SPEED;
    // alu computation result
    int alu_result;

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