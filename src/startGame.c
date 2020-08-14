#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/events.h"
#include "../headers/fps.h"

void startGame(SDL_Renderer *renderer, Game *game) {
  Planet planet;
  game->planet = &planet;
  planet.planetSurface = IMG_Load("img/planets/Earth.png");
  planet.planetTexture = SDL_CreateTextureFromSurface(renderer, planet.planetSurface);
  planet.w = 72;
  planet.h = 72;
  SDL_Rect planetRect = {(game->w-planet.w)/2, (game->h-planet.h)/2, planet.w, planet.h};
  SDL_RenderCopyEx(renderer, planet.planetTexture, NULL, &planetRect, 0, NULL, 0);
  SDL_RenderPresent(renderer);

  SDL_FreeSurface(planet.planetSurface);

  while (game->state == 1) {
    Uint32 ticks = SDL_GetTicks();
    events(game);
    fps(ticks);
  }
}

