#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../libs/objects.h"
#include "../libs/render.h"
#include "../libs/events.h"
#include "../libs/startGame.h"
#include "../libs/fps.h"

void mainMenu(SDL_Renderer *renderer, Game *game) {
    game->state = 0;
    game->wave = 0;
    renderSpace(renderer, game);
    renderPresent(renderer);

    // 0 menu, 1 started, 2 quit
    while (!game->state) {
        Uint32 ticks = SDL_GetTicks();
        events(game);
        fps(ticks);
    }

    switch (game->state) {
        case 1: startGame(renderer, game);
        case 2: return;
    }
}
