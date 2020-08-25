#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define FPS 60

void fps(Uint32 ticks) {
    Uint32 frame = SDL_GetTicks() - ticks;
    if ((1000/FPS) > frame) {
        SDL_Delay((1000/FPS) - frame);
    }
}
