/*
FILE
Pixel Processing Unit File

DESCRIPTION
Gives the overall details / specs of the CHIP-8 Pixels and screen size
*/
#include <stdint.h>
#include <SDL3/SDL.h>

#ifndef PPU_H
#define PPU_H

#include <stdint.h>
#include <SDL3/SDL.h>

// Screen size
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

// Global arrays
extern uint8_t screen_pix[SCREEN_WIDTH * SCREEN_HEIGHT];
extern uint8_t max_sprite_size[8*15];

// Function prototypes
void clear_screen(void);
void print_screen(SDL_Renderer* renderer, int scale);

#endif