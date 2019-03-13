#include "cpu.h"

Cpu::Cpu(int count, int base_address) : ir(count, base_address), alu(), ram()
{
    alu_result = 0;
    first_run = true;
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
    {
        first_run = false;
        ir.get_instruction();
    }
}

void Cpu::execute_instruction()
{   
    // LOAD
    if (ir.op_code == 0)
    {
        int temp = ram.read(ir.rd);
        ram.write(ir.rs0, temp);
    }
    // STORE
    if (ir.op_code == 1)
    {
        int temp = ram.read(ir.rs0);
        ram.write(ir.rd, temp);
    }
    // ADD, SUBTRACT, MULTIPLY, DIVIDE
    if (ir.op_code >= 2 && ir.op_code <= 5)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ram.read(ir.rs0);
        alu_result = alu.output_result(ir.op_code, val1, val0);
        ram.write(ir.rd, alu_result);
    }
    // LOOP
    if (ir.op_code == 6)
    {
        int loop_size = ram.read(ir.rs1);
        int pc_counter = ram.read(PC_ADDRESS);
        ram.write(ir.rd, pc_counter + loop_size);
    }
    // BGE
    if (ir.op_code == 7)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ram.read(ir.rs0);
        bool bge = alu.output_result(ir.op_code, val1, val0);
        if (bge == true)
        {
            int ra = ram.read(ir.rd); 
            ram.write(PC_ADDRESS, ra);
        }
        else
        {
            ; // normal program flow
        }
    }
    // JUMP TO
    if (ir.op_code == 8)
    {
        int counter = ram.read(PC_ADDRESS);
        int jump_back = ram.read(ir.rs1);
        ram.write(PC_ADDRESS, counter - jump_back);
    }
    // ADDI
    if (ir.op_code == 9)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ir.rs0;
        alu_result = alu.output_result(2, val1, val0);
        ram.write(ir.rd, alu_result);
    }
    // EQUAL
    if (ir.op_code == 10)
    {
        int val1 = ram.read(ir.rs1);
        int val0 = ram.read(ir.rs0);
        int eq = alu.output_result(ir.op_code, val1, val0);
        if (eq == 1)
        {
            ram.write(ir.rd, 1);
        }
        else
        {
            ;// Normal program flow
        }
    }
}
