/*
FILE: mem.c

DESCRIPTION
*/

// Defines
#include "mem.h"

// Declarations
uint8_t memory[4096];
uint8_t rom_size[ROM_MAX_SIZE];
uint8_t rom;

// State Machine

// Loads the ROM data from the game file
void load_rom(uint8_t *rom_data, uint8_t rom_size)
{

}

// Reads the ROM data to the MMU main memory 
void read_mem()
{
    for(int i = 0; i < rom_size; i++)
    {
        memory[0x200 + i] = rom[i];
    }
}

void write_mem()
{
    
}