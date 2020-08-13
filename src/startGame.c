#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/events.h"

void startGame(SDL_Renderer *renderer, Game *game) {
  SDL_Surface *surface = IMG_Load("img/planets/Earth.png");
  game->planetTexture = SDL_CreateTextureFromSurface(renderer, surface);
  game->planetW = 72;
  game->planetH = 72;
  SDL_Rect planetRect = {(game->w-game->planetW)/2, (game->h-game->planetH)/2, game->planetW, game->planetH};
  SDL_RenderCopyEx(renderer, game->planetTexture, NULL, &planetRect, 0, NULL, 0);
  SDL_RenderPresent(renderer);

  SDL_FreeSurface(surface);

  while (game->state == 1) {
    events(game);
  }
}

