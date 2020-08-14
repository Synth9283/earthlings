#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/render.h"
#include "../headers/events.h"
#include "../headers/process.h"
#include "../headers/fps.h"

void startGame(SDL_Renderer *renderer, Game *game) {
  Planet planet;
  game->planet = &planet;
  planet.w = 72;
  planet.h = 72;
  renderPlanet(renderer, game);
  renderPresent(renderer);

  while (game->state == 1) {
    Uint32 ticks = SDL_GetTicks();
    process(renderer, game);
    events(game);
    fps(ticks);
  }
}

