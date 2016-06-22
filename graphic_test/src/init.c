/*
** init.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:46:06 2016 Aurelie Orset
** Last update Wed Jun 22 14:40:57 2016 Aurelie Orset
*/

#include "graphic.h"

SDL_Surface *init(char *title, int x, int y)
{
  SDL_Surface *screen;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
      printf("Could not initialize SDL: %s\n", SDL_GetError());
      exit(1);
    }
  screen = SDL_SetVideoMode(x, y, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);
  if (screen == NULL)
    {
      printf("Couldn't set screen mode to 640 x 480: %s\n", SDL_GetError());
      exit(1);
    }
  SDL_WM_SetCaption(title, NULL);
  return (screen);
}
