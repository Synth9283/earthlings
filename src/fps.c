#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define FPS 60
#define FRAME_DELAY 1000/FPS

void fps(Uint32 ticks) {
    Uint32 frame = SDL_GetTicks() - ticks;
    if (FRAME_DELAY > frame) {
        SDL_Delay(FRAME_DELAY-frame);
    }
}
