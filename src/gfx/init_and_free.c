/*
** init_and_free.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sat Jun 25 14:13:05 2016 Aurelie Orset
** Last update Sun Jun 26 10:32:04 2016 Aurelie Orset
*/

#include "graphic.h"

t_info *init_and_resize(t_graph *g)
{
  t_info *i;

  i = init_info(g);
  i = resize_info(i, 0.5);
  return (i);
}

void *free_at_exit(t_graph *g, t_info *i)
{
  SDL_FreeSurface(g->screen);
  free_all_info(i);
  free_all(g);
  SDL_Quit();
  exit(0);
}
