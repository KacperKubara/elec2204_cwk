#include "ir.h"

Ir::Ir(int count, int base_address) : programCounter(count, base_address)
{
    set_instruction();
}

void Ir::set_next_instruction(void)
{
    programCounter.increment();
    set_instruction();
}

void Ir::set_instruction(void)
{
    int address = programCounter.get_counter();
    int reg_content;
    // hardcoded RAM values
    switch (address)
    {
        case RAM_PROGRAM_ADDRESS:
        reg_content = 0x00FFFAAA;
        break;

        case (RAM_PROGRAM_ADDRESS+1):
        reg_content = 0x01AAAFFF;
        break;

        case (RAM_PROGRAM_ADDRESS+2):
        reg_content = 0x02DDDBBB;
        break;

        default:
        reg_content = 0;
        break;
    }
    set_op(reg_content);
    set_regs(reg_content);
}
void Ir::set_op(int reg_content)
{
    Ir::op_code = (reg_content>>6*4);
}

void Ir::set_regs(int reg_content)
{
    rs0 = 0x00FF    & (reg_content>>4*4);
    rs1 = 0x0000FF  & reg_content>>2*4;
    rd  = 0;
}