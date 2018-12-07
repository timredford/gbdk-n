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

  sprite_init();

  sprite_create(&earthSprite, 0x1000, 0x1000, earth_tiles, 2, earth_data, 0x1C);

  spriteMoved = false;
  SHOW_SPRITES;
  DISPLAY_ON;

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
