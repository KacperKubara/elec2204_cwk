#include "cpu.h"

Cpu::Cpu(int count, int base_address) : ir(count, base_address), alu(), ram(true)
{
    // fix it
    alu_result = 0;
    first_run = true;
    ir.get_ram(ram);
    ir.get_instruction();
}

void Cpu::execute_cycle(void)
{
    fetch();
    execute_instruction();
}

void Cpu::fetch()
{
    if (first_run == false)
    {
        ir.get_next_instruction();
    }
    
    else first_run = false; 
}

void Cpu::execute_instruction()
{
    if (ir.op_code == 0)
    {
        int temp = ram.read(ir.rd);
        ram.write(ir.rs0, temp);
    }
    if (ir.op_code == 1)
    {
        int temp = ram.read(ir.rs0);
        ram.write(ir.rd, temp);
    }
    if (ir.op_code >= 2 && ir.op_code <= 5)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ram.read(ir.rs0);
        alu_result = alu.output_result(ir.op_code, val1, val0);
        ram.write(ir.rd, alu_result);
    }
}
