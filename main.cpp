#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "configure.h"
#include "./cpu/cpu.h"

using namespace std;

// globally defined cpu instance
Cpu cpu0(0, RAM_PROGRAM_ADDRESS);
Cpu cpu1(0, RAM_PROGRAM_ADDRESS);
// read data from .txt file
void read_data(string filename);
// converts assembly to machine code
int parse_assembly(string data);
//updates the program data with machine code commands from the file
void update_program_data(int data, int n);
// prints squared integer
void print_squared(void);
// prints prime numbers
void print_prime(void);

int main()
{

    print_squared();
    print_prime();
    return 0;
}

void read_data(string filename)
{
    string buffer;
    int temp;
    int i = 0;
    ifstream file;
    file.open(filename, ios::out | ios::in);
    while (getline(file, buffer))
    {
        if (i >= 31)
            break;
        temp = parse_assembly(buffer);
        update_program_data(i, temp);
        i++;
    }
    file.close();
}
int parse_assembly(string data)
{
    istringstream s(data);
    string buffer;
    string opcode;
    int temp_int;
    int op_code;
    int rs1;
    int rs0;
    int rd;

    s >> buffer;
    opcode = buffer;

    if (opcode == "LD")
        op_code = 0x00;
    if (opcode == "STR")
        op_code = 0x01;
    if (opcode == "ADD")
        op_code = 0x02;
    if (opcode == "SUB")
        op_code = 0x03;
    if (opcode == "MLT")
        op_code = 0x04;
    if (opcode == "DIV")
        op_code = 0x05;
    if (opcode == "LOOP")
        op_code = 0x06;
    if (opcode == "BGE")
        op_code = 0x07;
    if (opcode == "JI")
        op_code = 0x08;
    if (opcode == "ADDI")
        op_code = 0x09;
    if (opcode == "EQ")
        op_code = 0x0A;
    if (opcode == "END")
        op_code = 0x0F;

    // Map named regs to machine code
    for (int i = 0; i < 3; i++)
    {
        s >> buffer;
        int temp;

        if (buffer == "PC")
            temp = 0;
        if (buffer == "RA0")
            temp = 1;
        if (buffer == "RA1")
            temp = 2;
        if (buffer == "T0")
            temp = 5;
        if (buffer == "T1")
            temp = 6;
        if (buffer == "T2")
            temp = 7;
        if (buffer == "T3")
            temp = 8;
        if (buffer == "T4")
            temp = 9;
        if (buffer == "T5")
            temp = 10;
        if (buffer == "T6")
            temp = 11;
        if (buffer == "T7")
            temp = 12;
        if (buffer == "T8")
            temp = 13;
        if (buffer == "T9")
            temp = 14;
        if (buffer == "T10")
            temp = 15;

        if (buffer == "S0")
            temp = 16;
        if (buffer == "S1")
            temp = 17;
        if (buffer == "S2")
            temp = 18;
        if (buffer == "S3")
            temp = 19;
        if (buffer == "S4")
            temp = 20;
        if (buffer == "S5")
            temp = 21;
        if (buffer == "S6")
            temp = 22;
        if (buffer == "S7")
            temp = 23;
        if (buffer == "S8")
            temp = 24;
        if (buffer == "S9")
            temp = 25;
        if (buffer == "S10")
            temp = 26;
        if (buffer == "S11")
            temp = 27;
        if (buffer == "S12")
            temp = 28;
        if (buffer == "S13")
            temp = 29;
        if (buffer == "S14")
            temp = 30;
        if (buffer == "S15")
            temp = 31;

        if (i == 0)
            rs1 = temp;
        if (i == 1)
            rs0 = temp;
        if (i == 2)
            rd = temp;
    }

    op_code = op_code << 6 * 4;
    rs1 = rs1 << 4 * 4;
    rs0 = rs0 << 2 * 4;

    return (op_code | rs1 | rs0 | rd);
}
void update_program_data(int n, int data)
{
    bool success = true;
    int read;
    success = cpu0.ram.write(n + RAM_PROGRAM_ADDRESS - 1, data);
    read = cpu0.ram.read(n + RAM_PROGRAM_ADDRESS - 1);
    //cout << "Ram Write: " << std::hex << data << " Ram Read: " << std::hex << read << endl;
    if (!success)
        cout << "Error when writing the program data!" << endl;
}

void print_squared(void)
{
    int temp=0;
    read_data("assembly_squared.txt");
    /*for (int i = -1; i < RAM_PROGRAM_ADDRESS - 4; i += 4)
    {
        cout << std::hex << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 1) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 2) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 3) << endl;
    }*/

    for (int i = 0; i < 40; i++)
    {
        cpu0.execute_cycle();
        /*cout << endl
             << "__________________________________" << endl;
        cout << endl
             << i << " CYCLE EXECUTED" << endl;
        cout << "_____FETCHED INSTRUCTION_____" << endl;
        cout << "Counter: " << cpu0.ir.programCounter.get_counter() << endl;
        cout << "OP: " << std::hex << cpu0.ir.op_code << " RS1: " << cpu0.ir.rs1 << " RS0: " << cpu0.ir.rs0 << " RD: " << cpu0.ir.rd << endl;
        cout << "_____Core Regs Content_____" << endl;
        cout << "PC: " << cpu0.ram.read(0) << " "
             << " RA: " << cpu0.ram.read(1) << " T0: " << cpu0.ram.read(5) << " T1: " << cpu0.ram.read(6) << " T2: " << cpu0.ram.read(7) << endl;
        cout << "____RAM DATA_____" << endl;
        cpu0.ram.print_all();*/
        if (temp != cpu0.ram.read(9))
        {
            cout << "Squared Integer: " << std::dec << cpu0.ram.read(9) << std::hex << endl;
            temp = cpu0.ram.read(9);
        }
    }
}

void print_prime(void)
{
    read_data("assembly_prime.txt");
    /*for (int i = -1; i < RAM_PROGRAM_ADDRESS - 4; i += 4)
    {
        cout << std::hex << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 1) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 2) << " " << cpu0.ram.read(RAM_PROGRAM_ADDRESS + i + 3) << endl;
    }*/

    while (true)
    {
        cpu1.execute_cycle();
        /*cout << endl
             << "__________________________________" << endl;
        cout << endl
             << std::dec << i << " CYCLE EXECUTED" << std::hex<<endl;
        cout << "_____FETCHED INSTRUCTION_____" << endl;
        cout << "Counter: " << cpu0.ir.programCounter.get_counter() << endl;
        cout << "OP: " << std::hex << cpu0.ir.op_code << " RS1: " << cpu0.ir.rs1 << " RS0: " << cpu0.ir.rs0 << " RD: " << cpu0.ir.rd << endl;
        cout << "_____Core Regs Content_____" << endl;
        cout << "PC: " << cpu0.ram.read(0) << " "
             << " RA: " << cpu0.ram.read(1) << " T0: " << cpu0.ram.read(5) << " T1: " << cpu0.ram.read(6) << " T2: " << cpu0.ram.read(7) << endl;
        cout << "____RAM DATA_____" << endl;
        cpu0.ram.print_all();*/
        if (cpu1.ram.read(14) == 1)
        {
            cout << std::dec << "Prime number found: " << cpu1.ram.read(5) << std::hex << endl;
            if (cpu1.ram.read(5) >= 20)
                break;
        }
    }
}