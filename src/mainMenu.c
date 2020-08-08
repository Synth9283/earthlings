#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/objects.h"

void mainMenu(SDL_Renderer *renderer, SDL_Surface *surface, Game *game) {
  surface = IMG_Load("../img/space.png");
  game->spaceTexture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {game->w/2, game->h/2, game->w, game->h};
  SDL_RenderCopyEx(renderer, game->spaceTexture, NULL, &rect, 0, NULL, 0);
  SDL_RenderPresent(renderer);

  SDL_FreeSurface(surface);
}

