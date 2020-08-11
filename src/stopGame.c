#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void stopGame(SDL_Renderer *renderer, SDL_Window *window) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

