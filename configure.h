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
8-19  => Reg1
20-31 => Reg2
//////////////////
OP Code
0x00 - Load
0x01 - Store
0x02 - Add
0x03 - Subtract
0x04 - Multiply
0x05 - Divide
0x0F - End of program
//////////////////
RAM
Size: 256 Bytes (64 words)
0-31  => Data
32-64 => Program Data
//////////////////
*/