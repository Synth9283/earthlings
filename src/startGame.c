#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../libs/objects.h"
#include "../libs/render.h"
#include "../libs/events.h"
#include "../libs/process.h"
#include "../libs/fps.h"
#include "../libs/meteors.h"

void startGame(SDL_Renderer *renderer, Game *game) {
    Planet planet;
    game->planet = &planet;
    planet.w = 72;
    planet.h = 72;
    planet.radius = planet.w/2;
    planet.x = (game->w-planet.w)/2;
    planet.y = (game->h-planet.h)/2;
    game->meteors = NULL;
    renderPlanet(renderer, game);
    renderPresent(renderer);

    spawnMeteor(game);

    unsigned int tickCount = 0;

    while (game->state == 1) {
        Uint32 ticks = SDL_GetTicks();
        process(renderer, game);
        events(game);
        tickCount = updateMeteor(game, tickCount);
        fps(ticks);
    }
}
