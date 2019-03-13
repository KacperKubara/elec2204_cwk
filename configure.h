#define BASE_ADDRESS 0 // start address of PC
#define RAM_SIZE 64    // no. 32 bit registers
#define RAM_CORE_REGS 0// start address of core regs
#define RAM_DATA_ADDRESS 16    // start address of data in RAM 
#define RAM_PROGRAM_ADDRESS 32 // start address of program data in RAM
#define PC_ADDRESS 0  //address of Program Counter
#define RA0_ADDRESS 0 // Return Address Register 0
#define RA1_ADDRESS 1 // Return Address Register 1

/*
SPECIFICATIONS
//////////////////
Word_Size  : 32 bits
Number_Type: Integer
0-7   => OP Code
8-15  => rs1
16-23 => rs0
24-31 => rd
//////////////////
OP Code
0x00 - Load(LD)          |rs1  <-- rd|
0x01 - Store(STR)        |rs1  --> rd|
0x02 - Add(ADD)          |rs1 + rs0 --> rd|
0x03 - Subtract(SUB)     |rs1 - rs0 --> rd|
0x04 - Multiply(MLT)     |rs1 * rs0 --> rd|
0x05 - Divide(DIV)       |rs1 / rs0 --> rd|
0x06 - LOOP(LOOP)        |rs1 + PC  --> rd|
0x07 - BGE(BGE)          |rs1 >= rs0  rd?  PC <-- rd : PC = PC|
0x08 - jump to(JI)       |i --> PC - i|
0x09 - Add i (ADDI)      |rs1 + i --> rd|
0x0A - Equal(EQ)         |rs1 == rs0 rd? 1-->rd : 0-->rd|
0x0F - End of program(END)
//////////////////
RAM
Size: 256 Bytes (64 words)
0-15  => Core Regs
{
    0    => PC
    1    => RA
    2-4  => Core regs
    5-15 => Temp regs (T0,T1,...)
}
16-31 => Data (S0,S1,...)
32-64 => Program Data
//////////////////
*/