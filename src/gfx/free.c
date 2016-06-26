/*
** free.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 15:42:21 2016 Aurelie Orset
** Last update Sun Jun 26 10:33:37 2016 Aurelie Orset
*/

#include "graphic.h"

void	free_all(t_graph *g)
{
  SDL_FreeSurface(g->ground);
  SDL_FreeSurface(g->n);
  SDL_FreeSurface(g->l);
  SDL_FreeSurface(g->d);
  SDL_FreeSurface(g->s);
  SDL_FreeSurface(g->m);
  SDL_FreeSurface(g->p);
  SDL_FreeSurface(g->t);
  SDL_FreeSurface(g->nord);
  SDL_FreeSurface(g->sud);
  SDL_FreeSurface(g->est);
  SDL_FreeSurface(g->ouest);
  SDL_FreeSurface(g->nord2);
  SDL_FreeSurface(g->sud2);
  SDL_FreeSurface(g->est2);
  SDL_FreeSurface(g->ouest2);
  SDL_FreeSurface(g->egg);
  SDL_FreeSurface(g->incant);
  xfree(g);
}

void	free_all_info(t_info *g)
{
  TTF_CloseFont(g->police);
  SDL_FreeSurface(g->n);
  SDL_FreeSurface(g->l);
  SDL_FreeSurface(g->d);
  SDL_FreeSurface(g->s);
  SDL_FreeSurface(g->m);
  SDL_FreeSurface(g->p);
  SDL_FreeSurface(g->t);
  SDL_FreeSurface(g->info);
  xfree(g);
}
