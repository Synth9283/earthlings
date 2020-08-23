#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define FPS 60

void fps(Uint32 ticks) {
    if ((1000/FPS) > SDL_GetTicks() - ticks) {
        SDL_Delay(1000/FPS - (SDL_GetTicks() - ticks));
    }
}
