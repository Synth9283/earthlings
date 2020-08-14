#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "../headers/objects.h"

#define PI 3.14159265

void spawnMeteor(Game *game, Meteor *meteor) {
  unsigned int spawn = rand()%4;
  switch (spawn) {
    case 1:
      meteor->x = rand()%game->w-50;
      meteor->y = game->h-50;
      break;
    case 2:
      meteor->x = rand()%game->w-50;
      meteor->y = 50;
      break;
    case 3:
      meteor->x = game->w-50;
      meteor->y = rand()%game->h-50;
      break;
    case 4:
      meteor->x = 50;
      meteor->y = rand()%game->h-50;
      break;
  }
  printf("X: %d, Y: %d\n", meteor->x, meteor->y);
  //meteor->x = rand()%game->w;
  //meteor->y = rand()%game->h;
  meteor->w = 64;
  meteor->h = 64;
  meteor->health = 1;
  meteor->textureCount = 1;
  meteor->angle = atan2((game->h/2-meteor->y), (meteor->x/2-game->h))*(180/PI);
  printf("%f\n", meteor->angle);
}

unsigned int updateMeteor(Game *game, Meteor *meteor, unsigned int tickCount) {
  switch (tickCount) {
      case 15:
        tickCount = 0;
        switch (meteor->textureCount) {
          case 1:
            meteor->textureCount++;
            break;
          case 2:
            meteor->textureCount++;
            break;
          case 3:
            meteor->textureCount--;
            break;
          default:
            meteor->textureCount = 0;
            break;
          }
        break;
      default:
        tickCount++;
        break;
    }
  return tickCount;
}

