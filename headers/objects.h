#pragma once

typedef struct {
  int radius, x, y, lives;
} Earth;
typedef struct {
  int radius, x, y;
} Meteor;
typedef struct {
  int state, w, h, planetW, planetH;
  SDL_Texture *spaceTexture;
  SDL_Texture *planetTexture;
  SDL_Texture *fontTexture;
  TTF_Font *font;
} Game;

