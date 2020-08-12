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
  SDL_Rect planetRect = {game->w/2-game->planetW, game->h/2-game->planetH, game->planetW, game->planetH};
  SDL_RenderCopyEx(renderer, game->planetTexture, NULL, &planetRect, 0, NULL, 0);
  SDL_RenderPresent(renderer);

  SDL_FreeSurface(surface);
  
  SDL_Delay(5000);
  //while (!game->state) {
  //  events(game);
  //}
  //switch (game->state) {
  //  case 1: startGame(renderer, game);
  //  case 2: return;
  //}
}

