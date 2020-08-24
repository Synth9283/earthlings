#pragma once

typedef struct {
    int radius, x, y, w, h, lives;
    SDL_Surface *planetSurface;
    SDL_Texture *planetTexture;
} Planet;
typedef struct {
    int radius, x, y, w, h, health, textureCount;
    double angle;
    SDL_Surface *meteorSurface;
    SDL_Texture *meteorTexture;
    struct Meteor *next;
    struct Meteor *prev;
} Meteor;
typedef struct {
    int state, w, h, wave;
    Meteor *meteors;
    SDL_Surface *spaceSurface;
    SDL_Texture *spaceTexture, *fontTexture;
    TTF_Font *font;
    Planet *planet;
} Game;
