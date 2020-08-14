#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/render.h"
#include "../headers/events.h"
#include "../headers/process.h"
#include "../headers/fps.h"
#include "../headers/meteors.h"

void startGame(SDL_Renderer *renderer, Game *game) {
  Planet planet;
  game->planet = &planet;
  planet.w = 72;
  planet.h = 72;
  renderPlanet(renderer, game);
  renderPresent(renderer);

  Meteor meteor;
  game->meteors = &meteor;
  spawnMeteor(game, game->meteors);
  
  unsigned int tickCount = 0;

  while (game->state == 1) {
    Uint32 ticks = SDL_GetTicks();
    process(renderer, game);
    events(game);
    tickCount = updateMeteor(game, &meteor, tickCount);
    fps(ticks);
  }
}

