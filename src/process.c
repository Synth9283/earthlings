#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/render.h"

void process(SDL_Renderer *renderer, Game *game) {
  renderSpace(renderer, game);
  renderPlanet(renderer, game);
  renderPresent(renderer);
}

