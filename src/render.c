#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"

void renderSpace(SDL_Renderer *renderer, Game *game) {
  game->spaceSurface = IMG_Load("img/space.png");
  game->spaceTexture = SDL_CreateTextureFromSurface(renderer, game->spaceSurface);
  SDL_Rect rect = {0, 0, game->w, game->h};
  SDL_RenderCopyEx(renderer, game->spaceTexture, NULL, &rect, 0, NULL, 0);
  SDL_FreeSurface(game->spaceSurface);
}

void renderPlanet(SDL_Renderer *renderer, Game *game) {
  game->planet->planetSurface = IMG_Load("img/planets/Earth.png");
  game->planet->planetTexture = SDL_CreateTextureFromSurface(renderer, game->planet->planetSurface);
  SDL_Rect planetRect = {(game->w-game->planet->w)/2, (game->h-game->planet->h)/2, game->planet->w, game->planet->h};
  SDL_RenderCopyEx(renderer, game->planet->planetTexture, NULL, &planetRect, 0, NULL, 0);
  SDL_FreeSurface(game->planet->planetSurface);
}

void renderPresent(SDL_Renderer *renderer) {
  SDL_RenderPresent(renderer);
}

