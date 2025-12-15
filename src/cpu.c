/*
FILE

DESCRIPTION

*/

// Includes
#include "cpu.h"
CPU cpu;
cpu_intialise(&cpu);

void cpu_initialise(CPU* cpu)
{
    cpu->pc = 0x200;
}

void cpu_fetch()


