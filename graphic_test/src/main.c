/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Thu Jun 23 13:50:21 2016 Aurelie Orset
*/

#include "graphic.h"

int main(int ac, char **av)
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  SDL_Surface *screen;
  int	mapx;
  int	mapy;

  mapx = atoi(av[1]);
  mapy = atoi(av[2]);
  if (ac != 3)
    exit(0);
  if (TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }
  screen = init("MOUILLETTE ZAPPY", 1500, 1000);
  go = 1;
  while (go == 1)
    {
      draw(screen, mapx, mapy);
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }
  exit(0);
}
