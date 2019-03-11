#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "configure.h"
#include "./cpu/cpu.h"

using namespace std;

// globally defined cpu instance
//Cpu cpu0(0, RAM_PROGRAM_ADDRESS);

// read data from .txt file
void read_data(void);
// converts assembly to machine code
int parse_assembly(string data);
//updates the program data with machine code commands from the file
void update_program_data(int data, int n);

int main()
{
    read_data();
    return 0;
}

void read_data(void)
{
    string buffer;
    int temp;
    int i = 0;
    ifstream file;
    file.open("assembly.txt", ios::out | ios::in);
    while (getline(file, buffer))
    {
        if (i >= 31)
            break;
        temp = parse_assembly(buffer);
        cout << buffer << endl;
        cout << std::hex << temp << endl;
        update_program_data(temp, i);
        i++;
    }
    file.close();
}
int parse_assembly(string data)
{   
    istringstream s(data);
    string buffer;
    string opcode;
    int op_code;
    int rs1;
    int rs0;
    int rd;

    s >> buffer;
    opcode = buffer;

    if(opcode == "LD")  op_code = 0x00;
    if(opcode == "STR") op_code = 0x01;
    if(opcode == "ADD") op_code = 0x02;
    if(opcode == "SUB") op_code = 0x03;
    if(opcode == "MLT") op_code = 0x04;
    if(opcode == "DIV") op_code = 0x05;
    if(opcode == "END") op_code = 0x0F;

    s >> buffer;
    rs1 = stoi(buffer);
    s >> buffer;
    rs0 = stoi(buffer);
    s >> buffer;
    rd  = stoi(buffer);

    op_code = op_code << 6*4;
    rs1 = rs1 << 4*4;
    rs0 = rs0 << 2*4;

    return (op_code | rs1 | rs0 | rd );
}
void update_program_data(int data, int n)
{
    ;
}