#include "ir.h"
#include "../hardcoded.cpp"

Ir::Ir(int count, int base_address) : programCounter(count, base_address)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        ram[i] = ram_hardcoded[i];
    }
    set_instruction();
}

void Ir::set_next_instruction(void)
{
    programCounter.increment();
    set_instruction();
}

void Ir::set_instruction(void)
{
    unsigned int *address;
    address = programCounter.get_counter() + &ram_hardcoded[0];
    int reg_content = *address;
    set_op(reg_content);
    set_regs(reg_content);
}
void Ir::set_op(int reg_content)
{
    Ir::op_code = (reg_content >> 6 * 4);
}

void Ir::set_regs(int reg_content)
{
    rs0 = 0xFF & (reg_content >> 4 * 4);
    rs1 = 0xFF & (reg_content >> 2 * 4);
    rd  = 0xFF & (reg_content);
}
