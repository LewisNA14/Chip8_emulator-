/*
FILE: cpu.c

DESCRIPTION:

*/

// Includes
#include "cpu.h"
#include "mem.h"

// Defines
CPU cpu;

// State Machine / Functions
void cpu_initialise(CPU* cpu)
{
    // Clear Variables
    cpu->pc = 0x200;
    cpu->sp = 0;              // reset stack pointer
    cpu->I = 0;                // reset index register
    cpu->delay_timer = 0;      // reset timers
    cpu->sound_timer = 0;

    // Clear Arrays
    memset(cpu->V, 0, 16);    // clear general registers
    memset(cpu->stack, 0, sizeof(cpu->stack));
    memset(cpu->key, 0, sizeof(cpu->key));
}

// Fetches the instructions from Memory
void cpu_fetch(CPU* cpu)
{
    cpu->opcode = memory[cpu->pc] << 8 | memory[cpu->pc + 1];
    cpu->pc += 2;
}

// Decodes the instructions fetched from  memory
void cpu_decode(CPU* cpu)
{
    switch(cpu->opcode & 0xF000)
    {
        // CLS, RET, SYS
        case 0x0000: 

        break;

        // JP Address
        case 0x1000:

        break;

        // Call Address
        case 0x2000:

        break;

        // SE Vx, Byte
        case 0x3000:

        break;

        // SNE Vx, Byte
        case 0x4000:

        break;

        // SE Vx, Vy
        case 0x5000:

        break;

        // LD Vx, Byte
        case 0x6000:

        break;
        
        // ADD Vx, byte
        case 0x7000:

        break;

        // LD, OR, AND, XOR, ADD, SUB, SHR, SUBN, SHL (Vx, Vy)
        case 0x8000:

        break;
        
        // SNE Vx, Vy 
        case 0x9000:

        break;

        // LD I, Address
        case 0xA000:

        break;

        // JP V0, Address
        case 0xB000:

        break;

        // RND Vx, Byte
        case 0xC000:

        break;

        // DRW Vx, Vy, nibble
        case 0xD000:

        break;

        // SKP, SKNP Vx
        case 0xE000:

        break;

        // LD (DT, ST, F, B, [I]) ADD (I),  
        case 0xF000:

        break;
    }
}

void cpu_execute(CPU* cpu)
{

}

