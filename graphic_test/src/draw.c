/*
** draw.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:46:16 2016 Aurelie Orset
** Last update Fri Jun 17 14:46:18 2016 Aurelie Orset
*/

#include "draw.h"

extern void drawMap(void);

void draw()
{
	drawMap();
	SDL_Flip(screen);
	SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
  unsigned int ticks = SDL_GetTicks();
  if (frameLimit < ticks)
    return;
  if (frameLimit > ticks + 16)
    SDL_Delay(16);
  else
    SDL_Delay(frameLimit - ticks);
}
