/*
FILE: mem.h
Memory Header File

DESCRIPTION
Contains the Memory size among other things to replicate hardware specs
*/

#include <stdio.h>
#include <stdint.h>

#ifndef MEM_H
#define MEM_H

// Declarations
#define ROM_MAX_SIZE 4096
#define MEMORY_MAX_SIZE 4096

extern uint8_t memory[MEMORY_MAX_SIZE];        // Full Memory Size
extern uint8_t rom[ROM_MAX_SIZE];    // Full ROM array
extern uint8_t rom_size;            // acts as a index

// Function Prototypes
void write_mem();        // Write to Memory
void read_mem();         // Read from Memory
void clear_mem();        // Delete / Clear Memory

#endif

