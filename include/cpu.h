/*
FILE
This file is the header for the CPU Source File declaring all the necessary interfaces
DESCRIPTION
*/

// Includes
#include <stdint.h>
#include <stdio.h>

#ifndef CPU_H
#define CPU_H

// Struct Definitions
typedef struct{
    uint16_t opcode;      // Operator Code
    unsigned char V[16];         // General Purpose registers
    uint16_t I;                  // Index 
    uint16_t pc;                // Program Counter

    // The Stack
    uint16_t stack[16];
    uint8_t sp;                 // Stack Pointer

    // Timers
    unsigned char delay_timer;
    unsigned char sound_timer;

    // Keypad
    unsigned char key[16];
} CPU;

// Function Prototypes
void cpu_initialise(CPU* cpu);
void cpu_fetch(CPU* cpu);
void cpu_decode(CPU* cpu);
void cpu_execute(CPU* cpu);

#endif