#define CLOCK_SPEED 1  // [Hz]
#define BASE_ADDRESS 0 // start address of PC
#define RAM_SIZE 64    // no. 32 bit registers
#define RAM_DATA 0     // start address of data in RAM 
#define RAM_PROGRAM 32 // start address of program in RAM
/*
SPECIFICATIONS
//////////////////
Word_Size: 32 bits
0-3   => OP Code
4-17  => Reg1
18-31 => Reg2
//////////////////
OP Code
0x0 - Load
0x1 - Store
0x2 - Add
0x3 - Subtract
0x4 - Multiply
0x5 - Divide
0xF - End of program
//////////////////
RAM
Size: 256 Bytes (64 words)
0-31  => Data
32-64 => Program
//////////////////
*/