#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c1, c2, c3, c4, c5, c6, c7, c8;

  c1.red = 238;
  c1.green = 130;
  c1.blue = 238;

  c2.red = 255;
  c2.green = 0;
  c2.blue = 255;

  c3.red = 186;
  c3.green = 85;
  c3.blue = 211;

  c4.red = 147;
  c4.green = 112;
  c4.blue = 219;

  c5.red = 138;
  c5.green = 43;
  c5.blue = 226;

  c6.red = 148;
  c6.green = 0;
  c6.blue = 211;

  c7.red = 139;
  c7.green = 0;
  c7.blue = 139;

  c8.red = 75;
  c8.green = 0;
  c8.blue = 130;

  clear_screen(s);

  //now let the art commence - split coordiante plane into sixteenths
  //setup x axis, y axis, y = x, y = -x
  draw_line(0, 250, 500, 250, s, c1); //x axis
  draw_line(250, 0, 250, 500, s, c1); //y axis
  draw_line(0, 0, 500, 500, s, c2); //y = x
  draw_line(0, 500, 500, 0, s, c1); //y = -x

  draw_line(250, 250, 500, 375, s, c3); //octant I, slope = 0.5
  draw_line(250, 250, 333, 500, s, c4); //octant II, slope = 1.51
  draw_line(250, 250, 500, 125, s, c5); //octant VIII, slope = -0.5
  draw_line(250, 250, 333, 0, s, c6); //octant VII, slope = -1.51

  draw_line(250, 250, 0, 125, s, c3); //octant V
  draw_line(250, 250, 167, 0, s, c4); //octant VI
  draw_line(250, 250, 0, 375, s, c5); //octant IV
  draw_line(250, 250, 167, 500, s, c6); //octant III

  display(s);
  save_extension(s, "lines.png");
}
