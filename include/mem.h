/*
FILE
Memory Header File

DESCRIPTION
Contains the Memory size among other things to replicate hardware specs
*/

#include <stdio.h>
#include <stdint.h>

#ifndef MEM_H
#define MEM_H
// Defines
extern unsigned char memory[4096];  // Memory Size

// Function Prototypes
void write_mem(memory *mem);        // Write to Memory
void read_mem(memory *mem);         // Read from Memory
void clear_mem(memory *mem);        // Delete / Clear Memory

#endif