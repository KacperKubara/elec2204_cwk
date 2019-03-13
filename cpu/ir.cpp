#include "ir.h"
#include<iostream>
Ir::Ir(int count, int base_address) : ram(true), programCounter(count, base_address)
{
 ;
}
void Ir::get_next_instruction(void)
{
    programCounter.increment();
    get_instruction();
}

void Ir::get_instruction(void)
{
    int address = programCounter.get_counter();
    int reg_content = ram.read(address);
    set_op(reg_content);
    set_regs(reg_content);
}

void Ir::set_op(int reg_content)
{
    op_code = (reg_content >> 6 * 4);
}

void Ir::set_regs(int reg_content)
{
    rs1 = 0xFF & (reg_content >> 4 * 4);
    rs0 = 0xFF & (reg_content >> 2 * 4);
    rd  = 0xFF & (reg_content);
}
void Ir::print_all(void)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        std::cout << std::hex << ram.read(i) << " ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
}