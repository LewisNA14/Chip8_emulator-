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
    uint8_t x = (cpu->opcode & 0x0F00) >> 8     // Extract bits 8-11 Vx
    uint8_t y = (cpu->opcode & 0x00F0) >> 4     // Extract bits 4-7 Vy

    switch(cpu->opcode & 0xF000)
    {
        // CLS, RET, SYS
        case 0x0000:
            switch(cpu->opcode & 0x00FF)
            {
                // CLS 
                case 0x00E0:
                
                break;
                // RET
                case 0x00EE:
                
                break;
                // SYS Address
                default:

                break;
            }
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
            switch (cpu->opcode & 0x000F)
            {
                // LD Vx, Vy
                case 0x0:

                break;

                // OR Vx, Vy
                case 0x1:
                
                break;

                // AND Vx, Vy
                case 0x2:

                break;

                // XOR Vx, Vu
                case 0x3:

                break;

                // ADD Vx, Vy
                case 0x4:

                break;

                // SUB Vx, Vy
                case 0x5:

                break;

                // SHR Vx {, Vy}
                case 0x6:

                break;

                // SUBN Vx, Vy
                case 0x7:

                break;

                // SHL Vx {, Vy}
                case 0xE:

                break;
        }
        
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
            switch(cpu->opcode & 0x00FF)
            {
                // SKP Vx
                case 0x9E:

                break;

                // SKNP Vx
                case 0xA1:

                break;
            }
        break;

        // LD (DT, ST, F, B, [I]) ADD (I),  
        case 0xF000:
            switch(cpu->opcode & 0x00FF)
            {
                // LD Vx, DT
                case 0x07:

                break;
                
                // LD Vx, K
                case 0x0A:
                
                break;

                // LD DT, Vx
                case 0x15:

                break;

                // LD ST, Vx
                case 0x18:

                break;

                // ADD I, Vx
                case 0x1E:

                break;

                // LD F, Vx
                case 0x29:

                break;

                // LD B, Vx
                case 0x33:

                break;

                // LD [I], Vx
                case 0x55:

                break;

                // LD Vx, [I]
                case 0x65:

                break;
            }
        break;

        default:
        // TODO: Unknown opcode - handle errors
        break;
    }
}

void cpu_execute(CPU* cpu)
{

}

// Test Function
int main (void)
{
    cpu_initialise()
    cpu_fetch()
}