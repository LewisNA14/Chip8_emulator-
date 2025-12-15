// Includes
#include <SDL3/SDL.h>


int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "CHIP-8 Emulator",
        640,            // width
        320,            // height
        SDL_WINDOW_RESIZABLE
    );

    SDL_Delay(2000); // keep window open 2 seconds
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
