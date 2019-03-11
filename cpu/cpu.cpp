#include "cpu.h"

Cpu::Cpu(int count, int base_address) : ir(count, base_address), alu(), ram(true)
{
    // fix it
    alu_result = 0;
    ir.get_ram(ram);
}

void Cpu::execute_cycle(void)
{
    fetch();
    execute_instruction();
}

void Cpu::fetch()
{
    ir.get_next_instruction();
}
void Cpu::execute_instruction()
{
    if (ir.op_code == 0)
    {
        ;
    }
    if (ir.op_code == 1)
    {
        ;
    }
    if (ir.op_code >= 2 && ir.op_code <= 5)
    {
        alu_result = alu.output_result(ir.op_code, ir.rs0, ir.rs1);
        save_result(alu_result);
    }
}
void Cpu::save_result(int result)
{
    ;
}
