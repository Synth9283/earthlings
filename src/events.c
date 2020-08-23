#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../libs/objects.h"
#include "../libs/scanKey.h"

void events(Game *game) {
    SDL_Event event;
    scanKey(game);
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE:
                game->state = 2;
                break;
            case SDL_QUIT:
                game->state = 2;
                break;
        }
    break;
    }
}
