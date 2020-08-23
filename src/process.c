#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../libs/objects.h"
#include "../libs/render.h"

void process(SDL_Renderer *renderer, Game *game) {
    renderSpace(renderer, game);
    renderPlanet(renderer, game);
    renderMeteor(renderer, game->meteors);
    renderPresent(renderer);
}
