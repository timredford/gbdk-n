#include "sprite.h"

void sprite_moveRelative(sprite_t* s, INT8 x, INT8 y)
{
  s->posx.w += x;
  s->posy.w += y;
}
