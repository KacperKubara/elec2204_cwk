#include "ir.h"
#include "../hardcoded.cpp"

Ir::Ir(int count, int base_address) : programCounter(count, base_address)
{
    ;
}
void Ir::get_ram(Ram &ram_object)
{
    ram = ram_object;
}
void Ir::get_next_instruction(void)
{
    programCounter.increment();
    get_instruction();
}

void Ir::get_instruction(void)
{
    unsigned int *address;
    address = programCounter.get_counter() + ram;
    int reg_content = *address;
    set_op(reg_content);
    set_regs(reg_content);
}
void Ir::set_op(int reg_content)
{
    op_code = (reg_content >> 6 * 4);
}

void Ir::set_regs(int reg_content)
{
    rs0 = 0xFF & (reg_content >> 4 * 4);
    rs1 = 0xFF & (reg_content >> 2 * 4);
    rd = 0xFF & (reg_content);
}
