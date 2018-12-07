#include "sprite.h"
#include <gb/drawing.h>
#include <gb/gb.h>

#define TOTAL_NUM_SPRITE_TILES 50

 UINT8 next_SpriteTile;
 UINT8 next_SpriteDataTile;

void sprite_init()
{
  /* Initialize sprite palette */
  OBP1_REG = 0xE0U;
  SPRITES_8x16; // this might go somewhere else so the sprite can be size agnostic

  next_SpriteTile = 0;
  next_SpriteDataTile = 0;
}

void sprite_create(
  sprite_t* s,
  WORD x, WORD y,
  unsigned char * inAnimations,
  UBYTE inNumSpriteTiles,
  unsigned char* data,
  UINT8 dataLength)
{
  UBYTE i;
  s->posx.w = x;
  s->posy.w = y;
  s->animations = inAnimations;
  s->animFrame = 0;
  s->numSpriteTiles = inNumSpriteTiles;
  
  for(i =0; i < inNumSpriteTiles; i++)
  {
    s->spriteTileValues[i] = next_SpriteTile++;
    if(next_SpriteTile == TOTAL_NUM_SPRITE_TILES )
    {
      gprint("ERROR: SPRITE_INIT");
    }
  }


  set_sprite_data(next_SpriteDataTile, dataLength, data);
  next_SpriteDataTile += dataLength;

  for(i =0; i < inNumSpriteTiles; i++)
  {
    set_sprite_tile(i, s->animations[s->animFrame + i]);
    move_sprite(i, s->posx.b.h + (i * 8), s->posy.b.h); //assuming horizontally tiles

  }
}

void sprite_moveRelative(sprite_t* s, INT8 x, INT8 y)
{
  s->posx.w += x;
  s->posy.w += y;
}
