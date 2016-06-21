/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Mon Jun 20 16:55:20 2016 Aurelie Orset
*/

#include "graphic.h"

int main(int ac, char **av)
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  SDL_Surface *screen;

  screen = init("MOUILLETTE ZAPPY");
  go = 1;
  while (go == 1)
    {
      getInput();
      draw(screen);
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }
  exit(0);
}
