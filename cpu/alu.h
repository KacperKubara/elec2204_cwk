#include "../configure.h"

class Alu
{   
    public:
    bool signal = 0; // 0 -wrong opcode, 1 - correct opcode, result ready
    // output result
    int output_result(int opcode, int val1, int val0);
    // sum function
    int sum(int val1, int val0);
    // subtract function
    int subtract(int val1, int val0);
    // multiply function
    int multiply(int val1, int val0);
    // divide function
    int divide(int val1, int val0);
};