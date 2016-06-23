/*
** init_info.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Thu Jun 23 13:16:06 2016 Aurelie Orset
** Last update Thu Jun 23 13:16:35 2016 Aurelie Orset
*/

#include "graphic.h"

t_info	*init_info()
{
  t_info *i;

  i = malloc(sizeof(t_info));
  i->n = loadImage("gfx/cake_big.png");
  i->l = loadImage("gfx/linemate_large.png");
  i->d = loadImage("gfx/deraumire_large.png");
  i->s = loadImage("gfx/sibur_large.png");
  i->m = loadImage("gfx/mendiane_large.png");
  i->p = loadImage("gfx/phiras_large.png");
  i->t = loadImage("gfx/thystame_large.png");
  i->info = loadImage("gfx/info.png");
  if ((i->police = TTF_OpenFont("gfx/font.ttf", 55)) == NULL)
    printf("no load\n");
  i->color.r = 255;
  i->color.g = 255;
  i->color.b = 255;
  return (i);
}

t_info *resize_info(t_info *i)
{
  i->n = rotozoomSurface(i->n, 0.0, 0.5, 1);
  i->l = rotozoomSurface(i->l, 0.0, 0.5, 1);
  i->d = rotozoomSurface(i->d, 0.0, 0.5, 1);
  i->s = rotozoomSurface(i->s, 0.0, 0.5, 1);
  i->m = rotozoomSurface(i->m, 0.0, 0.5, 1);
  i->p = rotozoomSurface(i->p, 0.0, 0.5, 1);
  i->t = rotozoomSurface(i->t, 0.0, 0.5, 1);
  return (i);
}
