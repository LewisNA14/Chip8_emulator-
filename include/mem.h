/*
FILE: mem.h
Memory Header File

DESCRIPTION
Contains the Memory size among other things to replicate hardware specs
*/

#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdint.h>

// Memory
#define MEMORY_MAX_SIZE 4096                
#define PROGRAM_START   0x200               // Programs starting address
extern uint16_t memory[MEMORY_MAX_SIZE];  // Memory Buffer

// ROM
#define ROM_MAX_SIZE 4096
extern uint16_t rom[ROM_MAX_SIZE];        // ROM Buffer
extern uint16_t rom_size;                 // number of bytes loaded
extern FILE *rom_fp;                      // ROM file pointer

// Function prototypes
void read_rom(void);
void load_rom(const uint8_t *rom_bytes, uint16_t rom_len); // load ROM into buffer
void map_rom_to_memory(void);                                // copy ROM into memory
void clear_mem(void);                                        // clear memory


#endif
