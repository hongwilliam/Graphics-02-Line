#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//assume line with defined slope
double slope(int x, int y, int x1, int y1){
  return ((double) y1 - y) / ((double) x1 - x); }

//assume that x0 < x1 (subsequent pixel is to right)
//return 1, 2, 7, 8 for octants
int octant(int x, int y, int x1, int y1){
  //note that we only need octs 1, 2, 7, 8
  //5 is 1, 6 is 2, 4 is 8, 3 is 7

  //undefined slope - vertical line
  if (x == x1){
    //octants 2 are closer to y axis
    return 2; }

  double line_slope = slope(x, y, x1, y1);

  //octant 1
  if (line_slope >= 0 && line_slope < 1){
    return 1; }

  //octant 2
  else if (line_slope >= 1){
    return 2; }

  //octant 7
  else if (line_slope < -1){
    return 7;
  }

  //octant 8
  else if (line_slope >= -1){
    return 8; }

  return 0; //error, debug code
}

//Insert your line algorithm here
//assume that we work from left to right (x0 < x1)
//we only need octants I, II, VII, VIII
void draw_line(int x, int y, int x1, int y1, screen s, color c) {

  if (x1 < x){
    int temp = x;
    x = x1;
    x1 = temp;
    temp = y;
    y = y1;
    y1 = temp; }

  int line_octant = octant(x, y, x1, y1);
  //use pseudo code from class
  int d; ///2A + B, varies based on octant
  int A = y1 - y, B = -(x1 - x); //A = delta y, B = negative delta x, constant for all octants

  //straight from class
  if (line_octant == 1){
    d = (2 * A) + B;

    while (x <= x1){
      plot(s, c, x, y);

      if (d > 0){
        y++;
        d += (2 * B); }

      x++;
      d += (2 * A);
    }
  }

  //also again, straight from class
  else if (line_octant == 2){
    d = A + (2 * B);

    while (y <= y1){
      plot(s, c, x, y);

      if (d < 0){
        x++;
        d += (2 * A); }

      y++;
      d += (2 * B);
    }
  }

  else if (line_octant == 7) {
    d = A - (2 * B);

    while (y >= y1) {
      plot(s, c, x, y);

      if (d > 0){
	       x++;
	       d += (2 * A); }

      y--;
      d -= (2 * B);
    }
  }

  else if (line_octant ==8 ) {
    d = (2 * A) - B;

    while (x <= x1){
      plot(s, c, x, y);

      if (d < 0){
	       y--;
	       d -= (2 * B); }

      x++;
      d += (2 * A);
    }
  }

}
