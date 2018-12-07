#ifndef SPRITE_H
#define SPRITE_H

#include <types.h>

#define MAX_NUM_SPRITE_TILES 2
typedef struct
{
  fixed posx;
  fixed posy;
  UBYTE animFrame;
  unsigned char * animations;
  UBYTE numSpriteTiles;
  UBYTE spriteTileValues[MAX_NUM_SPRITE_TILES];
} sprite_t;

void sprite_init();

void sprite_create(
  sprite_t* s,
  WORD x, WORD y,
  unsigned char * inAnimations,
  UBYTE inNumSpriteTiles,
  unsigned char* data,
  UINT8 dataLength);

void sprite_moveRelative(sprite_t* s, INT8 x, INT8 y);

#endif //SPRITE_H
