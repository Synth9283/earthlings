#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"

void scanKey(Game *game) {
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  // if in the main menu
  if (!game->state) {
    if (state[SDL_SCANCODE_RETURN]) {
      game->state = 1;
    }
    else if (state[SDL_SCANCODE_ESCAPE]) {
      game->state = 2;
    }
  }
  // if the game started
  else {
    return;
  }
}

