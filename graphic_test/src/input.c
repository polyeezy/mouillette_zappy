/*
** input.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:47:38 2016 Aurelie Orset
** Last update Wed Jun 22 14:48:37 2016 Aurelie Orset
*/

#include "graphic.h"

void getInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  exit(0);
	  break;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      exit(0);
	      break;
	    default:
	      break;
	    }
	  break;
	}
    }
}
