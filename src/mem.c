/*
FILE: mem.c

DESCRIPTION
*/

// Defines
#include "mem.h"
#include <string.h>

// Declarations

// Memory
uint16_t memory[MEMORY_MAX_SIZE];    // Memory Buffer

// ROM
uint16_t rom[ROM_MAX_SIZE];          // ROM Max Buffer
uint16_t rom_size = 0;               // ROM size in 16-bit words

// Clear memory
void clear_mem(void)
{
    memset(memory, 0, sizeof(memory));
}

// Read the ROMs contents 
void read_rom(void)
{
    // File Pointer opens the ROM game file
    FILE *rom_fp = fopen("roms/PONG", "rb");

    // Checks if the file pointer is NULL
    if (!rom_fp) {
        perror("Failed to open ROM");
        return;
    }

    // Get file size
    fseek(rom_fp, 0, SEEK_END);
    long file_size = ftell(rom_fp);
    
    // File size error handling
    if (file_size < 0) {
        perror("ftell failed");
        fclose(rom_fp);
        return;
    }
    
    fseek(rom_fp, 0, SEEK_SET);

    // Clamp size to ROM_MAX_SIZE in bytes
    if (file_size > MEMORY_MAX_SIZE - PROGRAM_START)
        file_size = MEMORY_MAX_SIZE - PROGRAM_START;

    // Read into temporary byte buffer
    uint8_t rom_bytes[file_size];
    fread(rom_bytes, 1, file_size, rom_fp);
    fclose(rom_fp);

    // Load ROM into 16-bit array
    load_rom(rom_bytes, (uint16_t)file_size);
}

// Load ROM
/* Parameters:
    rom_bytes - This is a pointer for the raw ROM bytes
    rom_len - the number of bytes in the ROM file

    Purpose:
    take the raw bytes from the ROM file and store them in a buffer (rom[]) or memory.
*/
void load_rom(const uint8_t *rom_bytes, uint16_t rom_len)
{
    if (rom_len > ROM_MAX_SIZE)
        rom_len = ROM_MAX_SIZE;

    for (uint16_t i = 0; i < rom_len; i++)
    {
        rom[i] = rom_bytes[i];   // store each byte in ROM buffer
    }

    rom_size = rom_len;           // track bytes in ROM
}

// Map ROM into memory starting at PROGRAM_START (0x200)
void map_rom_to_memory(void)
{
    for (uint16_t i = 0; i < rom_size; i++)
    {
        memory[PROGRAM_START + i] = rom[i];
    }
}

int main(void) 
{
    clear_mem();
    read_rom();
    map_rom_to_memory();

    printf("ROM size: %u\n", rom_size);
    printf("Memory[0x200]: 0x%04X\n", memory[PROGRAM_START]);

    return 0;
}