/*
Arduboy draw
November 19, 2016

This is a simple program to draw on the screen.

 The MIT License (MIT)
 Copyright (c) 2016 Paul & Ed Lafargue, paul@wizkers.io
 
  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the Software
  is furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Arduboy.h"

Arduboy arduboy;

// Coordinates of the cursor
byte x;
byte y;

byte oldx;
byte oldy;

// Sets up the console

void setup() {

  arduboy.begin();
  arduboy.setFrameRate(30);
  
  // Center our cursor
  x = WIDTH / 2;
  y = HEIGHT / 2;

  arduboy.clear();
  arduboy.display();
}


void loop() {

  if (!(arduboy.nextFrame()))
    return;

  oldx = x;
  oldy = y;
  boolean moved = false;

  if (arduboy.pressed(RIGHT_BUTTON) && (x < (WIDTH-1))) {
    x++;
    moved = true;
  }

  if (arduboy.pressed(LEFT_BUTTON) && (x > 0)) {
    x--;
    moved = true;
  }

  if (arduboy.pressed(UP_BUTTON) && (y > 0)) {
    y--;
    moved = true;
  }

  if (arduboy.pressed(DOWN_BUTTON) && (y < (HEIGHT-1))) {
    y++;
    moved = true;
  }

  if (arduboy.pressed(B_BUTTON)) {
    arduboy.clear();
  }

  // we set our cursor x pixels to the right and y down from the top
  arduboy.setCursor(x, y);
  arduboy.drawPixel(x, y, WHITE);

  // If we are not pressing the A button, we need to turn the old coordinates
  // to black
  if (!arduboy.pressed(A_BUTTON) && moved) {
    arduboy.drawPixel(oldx,oldy, BLACK);
  }
  
  // Display the new screen
  arduboy.display();
}
