/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Fri Jun 17 16:11:57 2016 Aurelie Orset
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void loadMap(char *);
extern SDL_Surface *loadImage(char *);
extern void draw(void);
extern void delay(unsigned int);

int main(int argc, char *argv[])
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;

  init("MOUILLETTE ZAPPY");
  atexit(cleanup);
  go = 1;
  brickImage = loadImage("gfx/grass.jpg");
  n = loadImage("gfx/food.png");
  l = loadImage("gfx/Linemate_smallpng.png");
  d = loadImage("gfx/deraumire_small.png");
  s = loadImage("gfx/sibur_small.png");
  m = loadImage("gfx/mendiane_small.png");
  p = loadImage("gfx/phiras_small.png");
  t = loadImage("gfx/thystame_small.png");
  if (brickImage == NULL)
    exit(1);
  loadMap("data/maps/map01.dat");
  while (go == 1)
    {
      getInput();
      draw();
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }
  exit(0);
}
