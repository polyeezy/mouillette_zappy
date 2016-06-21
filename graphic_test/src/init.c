/*
** init.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:46:06 2016 Aurelie Orset
** Last update Mon Jun 20 16:49:12 2016 Aurelie Orset
*/

#include "graphic.h"

SDL_Surface *init(char *title)
{
  SDL_Surface *screen;

  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
    {
      printf("Could not initialize SDL: %s\n", SDL_GetError());
      exit(1);
    }
  screen = SDL_SetVideoMode(1080, 720, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
  if (screen == NULL)
    {
      printf("Couldn't set screen mode to 640 x 480: %s\n", SDL_GetError());
      exit(1);
    }
  SDL_WM_SetCaption(title, NULL);
  /* Hide the mouse cursor */
  SDL_ShowCursor(SDL_DISABLE);
  return (screen);
}
