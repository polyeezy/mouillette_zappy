/*
** calc.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 24 12:02:13 2016 Aurelie Orset
** Last update Sat Jun 25 19:02:59 2016 Aurelie Orset
*/

#include "graphic.h"

float	calcCo(int mapx, int mapy, t_graph *g)
{
 int	calc;
 float	co;

 calc = mapx;
 if (calc < mapy)
   calc = mapy;
 co = 1000 / calc;
 co /= g->ts;
 return (co);
}

t_graph *resize(t_graph *g, float co)
{
  g->ground = rotozoomSurface(g->ground, 0.0, co, 1);
  g->n = rotozoomSurface(g->n, 0.0, co, 1);
  g->l = rotozoomSurface(g->l, 0.0, co, 1);
  g->d = rotozoomSurface(g->d, 0.0, co, 1);
  g->s = rotozoomSurface(g->s, 0.0, co, 1);
  g->m = rotozoomSurface(g->m, 0.0, co, 1);
  g->p = rotozoomSurface(g->p, 0.0, co, 1);
  g->t = rotozoomSurface(g->t, 0.0, co, 1);
  g->nord = rotozoomSurface(g->nord, 0.0, co, 1);
  g->sud = rotozoomSurface(g->sud, 0.0, co, 1);
  g->est = rotozoomSurface(g->est, 0.0, co, 1);
  g->ouest = rotozoomSurface(g->ouest, 0.0, co, 1);
  g->nord2 = rotozoomSurface(g->nord2, 0.0, co, 1);
  g->sud2 = rotozoomSurface(g->sud2, 0.0, co, 1);
  g->est2 = rotozoomSurface(g->est2, 0.0, co, 1);
  g->ouest2 = rotozoomSurface(g->ouest2, 0.0, co, 1);
  g->egg = rotozoomSurface(g->egg, 0.0, co, 1);
  g->incant = rotozoomSurface(g->incant, 0.0, co, 1);
  g->is = g->is * co;
  g->ts = g->ts * co;
  return (g);
}
