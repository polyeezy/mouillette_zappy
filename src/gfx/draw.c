/*
** draw.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:46:16 2016 Aurelie Orset
** Last update Thu Jun 23 20:24:05 2016 Aurelie Orset
*/

#include "graphic.h"

void draw(SDL_Surface *screen, int mapx, int mapy, t_client_socket client)
{
  drawMap(screen, mapx, mapy, client);
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
