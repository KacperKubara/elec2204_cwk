#include "cpu.h"

Cpu::Cpu(int count, int base_address) : ir(count, base_address), alu(), ram(true)
{
    alu_result = 0;
    first_run = true;
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

    else
        first_run = false;
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
    if (ir.op_code == 6)
    {
        int loop_size = ram.read(ir.rs1);
        int counter   = ram.read(PC_ADDRESS);
        ram.write(RA_ADDRESS, counter + loop_size);
    }
    if (ir.op_code == 7)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ram.read(ir.rs0);
        bool bge = alu.output_result(ir.op_code, val1, val0);
        if(bge == true)
        {   
            int ra = ram.read(RA_ADDRESS);// returns value from RA reg
            ram.write(PC_ADDRESS, ra);
        }
        else 
        {
            ;// normal program flow
        }
    }
    if (ir.op_code == 8)
    {   
        int counter = ram.read(PC_ADDRESS);
        ram.write(PC_ADDRESS,counter - ir.rs1);
    }
    if (ir.op_code == 9)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ir.rs0;
        alu_result = alu.output_result(2, val1, val0);
        ram.write(ir.rd, alu_result);
    }
}
