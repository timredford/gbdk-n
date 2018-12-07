#include <gb/gb.h>
#include <gb/drawing.h>
#include <types.h>
#include "sprite.h"
#include "res/earth.h"

#define true 1
#define false (!true)

sprite_t earthSprite;
void main()
{
  UBYTE s;
  UBYTE input;
  BOOLEAN spriteMoved;

  /* Initialize sprite palette */
  OBP1_REG = 0xE0U;

  earthSprite.posx.b.h = 50;
  earthSprite.posy.b.h = 50;
  earthSprite.animFrame = 0;
  earthSprite.animations = earth_tiles;


  SPRITES_8x16;
  set_sprite_data(0x00, 0x1C, earth_data);
  set_sprite_tile(0, earthSprite.animations[earthSprite.animFrame]);
  set_sprite_tile(1, earthSprite.animations[earthSprite.animFrame+1]);
  move_sprite(0, earthSprite.posx.b.h, earthSprite.posy.b.h);
  move_sprite(1, earthSprite.posx.b.h + 8, earthSprite.posy.b.h);
  spriteMoved = false;
  SHOW_SPRITES;

  gprintf("hello world");
  while(true)
  {
    input = joypad();
    if(input & J_UP)
    {
      sprite_moveRelative(&earthSprite, 0, -1);
      spriteMoved = true;
    }
    if(input & J_DOWN)
    {
      sprite_moveRelative(&earthSprite, 0, 1);
      spriteMoved = true;
    }
    if(input & J_LEFT)
    {
      sprite_moveRelative(&earthSprite, -1, 0);
      spriteMoved = true;
    }
    if(input & J_RIGHT)
    {
      sprite_moveRelative(&earthSprite, 1, 0);
      spriteMoved = true;
    }

    if(spriteMoved)
    {
      move_sprite(0, earthSprite.posx.b.h, earthSprite.posy.b.h);
      move_sprite(1, earthSprite.posx.b.h + 8, earthSprite.posy.b.h);
      spriteMoved = false;
    }
  }
}
