#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../libs/objects.h"

void renderSpace(SDL_Renderer *renderer, Game *game) {
    game->spaceSurface = IMG_Load("../img/space.png");
    game->spaceTexture = SDL_CreateTextureFromSurface(renderer, game->spaceSurface);
    SDL_Rect rect = {0, 0, game->w, game->h};
    SDL_RenderCopyEx(renderer, game->spaceTexture, NULL, &rect, 0, NULL, 0);
    SDL_FreeSurface(game->spaceSurface);
}

void renderPlanet(SDL_Renderer *renderer, Game *game) {
    game->planet->planetSurface = IMG_Load("../img/planets/Earth.png");
    game->planet->planetTexture = SDL_CreateTextureFromSurface(renderer, game->planet->planetSurface);
    SDL_Rect planetRect = {game->planet->x, game->planet->y, game->planet->w, game->planet->h};
    SDL_RenderCopyEx(renderer, game->planet->planetTexture, NULL, &planetRect, 0, NULL, 0);
    SDL_FreeSurface(game->planet->planetSurface);
}

void renderMeteor(SDL_Renderer *renderer, Meteor *meteor) {
    if (!meteor) return;
    Meteor *tmp = meteor;
    while (tmp) {
        switch (tmp->textureCount) {
            case 1:
                tmp->meteorSurface = IMG_Load("../img/meteor/Meteor1.png");
                break;
            case 2:
                tmp->meteorSurface = IMG_Load("../img/meteor/Meteor2.png");
                break;
            case 3:
                tmp->meteorSurface = IMG_Load("../img/meteor/Meteor3.png");
                break;
        }
        tmp->meteorTexture = SDL_CreateTextureFromSurface(renderer, tmp->meteorSurface);
        SDL_Rect meteorRect = {tmp->x, tmp->y, tmp->w, tmp->h};
        SDL_RenderCopyEx(renderer, tmp->meteorTexture, NULL, &meteorRect, tmp->angle, NULL, 0);
        SDL_FreeSurface(tmp->meteorSurface);
        tmp = (Meteor*)tmp->next;
    }
}

void renderPresent(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}
