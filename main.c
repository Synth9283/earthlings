#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "headers/objects.h"
#include "headers/mainMenu.h"
#include "headers/stopGame.h"

int main() {
  SDL_Window *window;
  SDL_Renderer *renderer;
  Game game;
  game.w = 640;
  game.h = 480;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  TTF_Init();
  window = SDL_CreateWindow("Earthlings", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game.w, game.h, 0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_Delay(50);
  mainMenu(renderer, &game);

  stopGame(renderer, window);
  return 0;
}

