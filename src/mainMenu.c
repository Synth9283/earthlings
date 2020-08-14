#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/render.h"
#include "../headers/events.h"
#include "../headers/startGame.h"
#include "../headers/fps.h"

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

