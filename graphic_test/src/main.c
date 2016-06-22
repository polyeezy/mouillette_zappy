/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Wed Jun 22 17:11:54 2016 Aurelie Orset
*/

#include "graphic.h"

int main(int ac, char **av)
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  SDL_Surface *screen;
  int	mapx;
  int	mapy;
  /*  int	calc;
  int	co;
  double xx;
  double yy;
  int	x;
  int	y;*/

  mapx = atoi(av[1]);
  mapy = atoi(av[2]);
  if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }
  /*calc = mapx;
    if (calc > mapy)
    calc = mapy;
  co = 1000/calc;
  co /= 96;
  xx = 1080 - mapx * co;
  x = xx;
  yy = 1000 - mapy * co;
  y = yy;*/
  screen = init("MOUILLETTE ZAPPY", 1500, 1000);
  go = 1;
  while (go == 1)
    {
      /*      getInput();*/
      draw(screen, mapx, mapy);
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }
  exit(0);
}
