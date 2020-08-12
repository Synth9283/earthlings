#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/objects.h"
#include "../headers/events.h"
#include "../headers/startGame.h"

void mainMenu(SDL_Renderer *renderer, Game *game) {
  game->state = 0;
  SDL_Surface *spaceSurface = IMG_Load("img/space.png");
  game->spaceTexture = SDL_CreateTextureFromSurface(renderer, spaceSurface);
  //game->font = TTF_OpenFont("fonts/pixel/advanced_pixel-7.ttf", 48);
  //if (game->font == NULL) printf("Failed to find font");
  SDL_Rect rect = {0, 0, game->w, game->h};
  SDL_RenderCopyEx(renderer, game->spaceTexture, NULL, &rect, 0, NULL, 0);
  //SDL_Color textColor = {0, 0, 255, 1};
  //SDL_Surface *fontSurface = TTF_RenderText_Solid(game->font, "Earthlings", textColor);
  //if (fontSurface == NULL) printf("Failed to render text solid");
  //game->fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
  //if (game->fontTexture == NULL) printf("Failed to create texture from surface");
  //SDL_QueryTexture(game->fontTexture, NULL, NULL, &game->w, &game->h);
  //SDL_Rect fontRect = {game->w/2, game->h/2, game->w/2, game->h/2};
  //SDL_RenderCopy(renderer, game->fontTexture, NULL, &fontRect);

  SDL_RenderPresent(renderer);

  //SDL_DestroyTexture(game->fontTexture);
  //TTF_CloseFont(game->font);
  //SDL_FreeSurface(fontSurface);
  SDL_FreeSurface(spaceSurface);

  // 0 menu, 1 started, 2 quit
  while (!game->state) {
    events(game);
  }
  switch (game->state) {
    case 1: startGame(renderer, game);
    case 2: return;
  }
}

