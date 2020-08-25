#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "../libs/objects.h"

#define PI 3.14159265

void spawnMeteor(Game *game) {
    Meteor *meteor = malloc(sizeof(Meteor));
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
    meteor->w = 64;
    meteor->h = 64;
    meteor->radius = meteor->w/2;
    meteor->health = 1;
    meteor->textureCount = 1;
    meteor->angle = atan2(game->planet->y-meteor->y, game->planet->x-meteor->x)*(180/PI);
    meteor->prev = NULL;

    if (game->meteors) {
        meteor->next = game->meteors->next;
        game->meteors = meteor;
    }
    else {
        meteor->next = NULL;
        game->meteors = meteor;
    }
}

int checkMeteor(Planet *planet, Meteor *meteor) {
    int dx = planet->x - meteor->x;
    int dy = planet->y - meteor->y;
    int distance = sqrt((dx*dx)+(dy*dy));
    if (distance > (planet->radius+meteor->radius)) return 1;
    else return 0;
}

void destroyMeteor(Game *game, Meteor *meteor) {
    Meteor *next = (Meteor*)meteor->next;
    Meteor *prev = (Meteor*)meteor->prev;
    if (next && prev) {
        next->prev = (struct Meteor*)prev;
        prev->next = (struct Meteor*)next;
    }
    else if (next) {
        next->prev = (struct Meteor*)NULL;
    }
    else if (prev) {
        meteor->next = (struct Meteor*)NULL;
    }
    else {
        game->meteors = NULL;
    }
    free(meteor);
}

void moveMeteor(Game *game, Meteor *meteor) {
    if (meteor->x > game->planet->x) meteor->x -= 5;
    else if (meteor->x < game->planet->x) meteor->x += 5;
    if (meteor->y > game->planet->y) meteor->y -= 2.5;
    else if (meteor->y < game->planet->y) meteor->y += 2.5;

    switch (checkMeteor(game->planet, meteor)) {
        // meteor didn't hit = 0, meteor hit = 1
        case 0:
            destroyMeteor(game, meteor);
            break;
        case 1: break;
    }
}

unsigned int updateMeteor(Game *game, unsigned int tickCount) {
    tickCount = 15;
    Meteor *tmp = game->meteors;
    switch (tickCount) {
        case 15:
            while (tmp) {
                switch (tmp->textureCount) {
                    case 1:
                        tmp->textureCount++;
                        break;
                    case 2:
                        tmp->textureCount++;
                        break;
                    case 3:
                        tmp->textureCount--;
                        break;
                    default:
                        tmp->textureCount = 0;
                        break;
                }
                moveMeteor(game, tmp);
                tmp = (Meteor*)tmp->next;
            }
            tickCount = 0;
            break;
        default:
            tickCount++;
            break;
    }
    return tickCount;
}
