#ifndef SPRITE_H
#define SPRITE_H

#include <types.h>

typedef struct {
  fixed posx;
  fixed posy;
  UBYTE animFrame;
  unsigned char * animations;
  UBYTE numSpriteTiles;
} sprite_t;

void sprite_moveRelative(sprite_t* s, INT8 x, INT8 y);

#endif //SPRITE_H
