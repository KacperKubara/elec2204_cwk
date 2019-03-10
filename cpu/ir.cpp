#include "ir.h"

Ir::Ir(int count, int base_address):programCounter(count, base_address)
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
    set_op(address);
    set_regs(address);

}
// Set methods are currently hardcoded
void Ir::set_op(int reg_content)
{
    op_code = 1;
}

void Ir::set_regs(int reg_content)
{
    reg1 = 1;
    reg2 = 2;
}