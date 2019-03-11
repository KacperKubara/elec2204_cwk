#define CLOCK_SPEED 1  // [Hz]
#define BASE_ADDRESS 0 // start address of PC
#define RAM_SIZE 64    // no. 32 bit registers
#define RAM_CORE_REGS 0// start address of core regs
#define RAM_DATA_ADDRESS 16    // start address of data in RAM 
#define RAM_PROGRAM_ADDRESS 32 // start address of program data in RAM
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
0x00 - Load     |rs1  <-- rd|
0x01 - Store    |rs1  --> rd|
0x02 - Add      |rs1 + rs0 --> rd|
0x03 - Subtract |rs1 - rs0 --> rd|
0x04 - Multiply |rs1 * rs0 --> rd|
0x05 - Divide   |rs1 / rs0 --> rd|
0x0F - End of program
//////////////////
RAM
Size: 256 Bytes (64 words)
0-15  => Core Regs
{
    0    => PC
    1-4  => Core regs
    5-15 => Temp regs (t0,t1,...)
}
16-31 => Data (s0,s1,...)
32-64 => Program Data
//////////////////
*/