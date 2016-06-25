/*
** init_info.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Thu Jun 23 13:16:06 2016 Aurelie Orset
** Last update Sat Jun 25 18:56:03 2016 Aurelie Orset
*/

#include "graphic.h"

t_info	*init_info(t_graph *g)
{
  t_info *i;

  i = xmalloc(sizeof(t_info));
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
  i->screen = g->screen;
  return (i);
}

t_info *resize_info(t_info *i, float co)
{
  i->n = rotozoomSurface(i->n, 0.0, co, 1);
  i->l = rotozoomSurface(i->l, 0.0, co, 1);
  i->d = rotozoomSurface(i->d, 0.0, co, 1);
  i->s = rotozoomSurface(i->s, 0.0, co, 1);
  i->m = rotozoomSurface(i->m, 0.0, co, 1);
  i->p = rotozoomSurface(i->p, 0.0, co, 1);
  i->t = rotozoomSurface(i->t, 0.0, co, 1);
  return (i);
}

t_graph *init_nemesis(t_graph *g)
{
  g->nord2 = loadImage("gfx/nord3.png");
  g->sud2 = loadImage("gfx/sud3.png");
  g->est2 = loadImage("gfx/est3.png");
  g->ouest2 = loadImage("gfx/ouest3.png");
  return (g);
}

t_graph	*init_graph(int x, int y, SDL_Surface *screen)
{
  t_graph *g;

  g = xmalloc(sizeof(t_graph));
  g->map_x = x;
  g->map_y = y;
  g->ground = loadImage("gfx/grass.jpg");
  g->n = loadImage("gfx/cake.png");
  g->l = loadImage("gfx/linemate_small.png");
  g->d = loadImage("gfx/deraumire_small.png");
  g->s = loadImage("gfx/sibur_small.png");
  g->m = loadImage("gfx/mendiane_small.png");
  g->p = loadImage("gfx/phiras_small.png");
  g->t = loadImage("gfx/thystame_small.png");
  g->nord = loadImage("gfx/nord.png");
  g->sud = loadImage("gfx/sud.png");
  g->est = loadImage("gfx/est.png");
  g->ouest = loadImage("gfx/ouest.png");
  g->egg = loadImage("gfx/egg.png");
  g->incant = loadImage("gfx/incant.png");
  g->screen = screen;
  g->is = 32;
  g->ts = 96;
  g = init_nemesis(g);
  return (g);
}

t_tile	*ressources(t_tile *tile, char *str)
{
  char **tab;

  tab = my_str_to_wordtab(str, " \n");
  if (strcmp(tab[0], "bct") == 0)
    {
      tile->n = atoi(tab[3]);
      tile->l = atoi(tab[4]);
      tile->d = atoi(tab[5]);
      tile->s = atoi(tab[6]);
      tile->m = atoi(tab[7]);
      tile->p = atoi(tab[8]);
      tile->t = atoi(tab[9]);
    }
  else
  {
    tile->n = 0;
    tile->l = 0;
    tile->d = 0;
    tile->s = 0;
    tile->m = 0;
    tile->p = 0;
    tile->t = 0;
  }
  return (tile);
}
