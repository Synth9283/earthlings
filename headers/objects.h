#pragma once

typedef struct {
  int radius, x, y, w, h, lives;
  SDL_Surface *planetSurface;
  SDL_Texture *planetTexture;
} Planet;
typedef struct {
  int radius, x, y;
} Meteor;
typedef struct {
  int state, w, h;
  SDL_Surface *spaceSurface;
  SDL_Texture *spaceTexture, *fontTexture;
  TTF_Font *font;
  Planet *planet;
} Game;

