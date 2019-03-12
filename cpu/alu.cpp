#include "alu.h"
Alu::Alu()
{
    signal = 0;
}

int Alu::output_result(int opcode, int val1, int val0)
{
    switch (opcode)
    {
    case 2:
        signal = 1;
        return sum(val1, val0);
        break;

    case 3:
        signal = 1;
        return subtract(val1, val0);
        break;

    case 4:
        signal = 1;
        return multiply(val1, val0);
        break;

    case 5:
        signal = 1;
        return divide(val1, val0);
        break;
    
    case 7:
        signal = 1;
        return bge(val1, val0);
        break;

    default:
        signal = 0;
        return 0;
    }
}

int Alu::sum(int val1, int val0)
{
    return val1 + val0;
}

int Alu::subtract(int val1, int val0)
{
    return val1 - val0;
}

int Alu::multiply(int val1, int val0)
{
    return val1 * val0;
}

int Alu::divide(int val1, int val0)
{
    return val1 / val0;
}

bool bge(int val1, int val0)
{
    if (val1 >= val0)
        return true;
    else
        return false;
}