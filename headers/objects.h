#pragma once

typedef struct {
  int radius, x, y, lives;
} Earth;
typedef struct {
  int radius, x, y;
} Meteor;
typedef struct {
  unsigned int started, w, h;
  SDL_Texture *spaceTexture;
} Game;

