#include <string>
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
        update_program_data(temp, i);
        i++;
    }
    file.close();
}
int parse_assembly(string data)
{
    ;
}
void update_program_data(int data, int n)
{
    ;
}