#include <SDL2/SDL.h>

void stopGame(SDL_Renderer *renderer, SDL_Window *window) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

