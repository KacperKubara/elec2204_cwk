#define CLOCK_SPEED 1  // [Hz]
#define BASE_ADDRESS 0 // start address of PC
#define RAM_SIZE 64    // no. 32 bit registers
#define RAM_DATA_ADDRESS 0     // start address of data in RAM 
#define RAM_PROGRAM_ADDRESS 32 // start address of program in RAM
/*
SPECIFICATIONS
//////////////////
Word_Size: 32 bits
0-7   => OP Code
8-15  => rs0
16-23 => rs1
24-31 => rd
//////////////////
OP Code
0x00 - Load     |rs0  --> rd|
0x01 - Store    |rs0  <-- rd|
0x02 - Add      |rs0 + rs1 --> rd|
0x03 - Subtract |rs0 - rs1 --> rd|
0x04 - Multiply |rs0 * rs1 --> rd|
0x05 - Divide   |rs0 / rs1 --> rd|
0x0F - End of program
//////////////////
RAM
Size: 256 Bytes (64 words)
0-15  => Core Regs
16-31 => Data
32-64 => Program Data
//////////////////
*/