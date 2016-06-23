/*
** info.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 14:18:08 2016 Aurelie Orset
** Last update Thu Jun 23 13:47:36 2016 Aurelie Orset
*/

#include "graphic.h"

int	convertX(int x, t_graph *g)
{
  double calc;

  calc = (x / g->ts);
  x = calc + 1;
  return (x);
}

void	drawTexte(t_info *i, int x, int y, char *str)
{
  SDL_Surface *texte;

  texte = TTF_RenderText_Solid(i->police, str, i->color);
  drawImage(texte, x, y, i->screen);
}

void	drawFood(t_info *i, t_graph *g)
{
  char *str;

  str = malloc(sizeof(str) * 15);
  i->screen = g->screen;
  sprintf(str, "%d", 122);
  drawImage(i->l, 1050, 100, g->screen);
  drawTexte(i, 1150, 110, str);
  sprintf(str, "%d", 213);
  drawImage(i->d, 1250, 100, g->screen);
  drawTexte(i, 1350, 110, str);
  sprintf(str, "%d", 2);
  drawImage(i->s, 1050, 200, g->screen);
  drawTexte(i, 1150, 210, str);
  sprintf(str, "%d", 2);
  drawImage(i->m, 1250, 200, g->screen);
  drawTexte(i, 1350, 210, str);
  sprintf(str, "%d", 2);
  drawImage(i->p, 1050, 300, g->screen);
  drawTexte(i, 1150, 310, str);
  sprintf(str, "%d", 29);
  drawImage(i->t, 1250, 300, g->screen);
  drawTexte(i, 1350, 310, str);
  sprintf(str, "%d", 2);
  drawImage(i->n, 1150, 400, g->screen);
  drawTexte(i, 1250, 410, str);
}

void	drawInfo(int x, int y, t_graph *g)
{
  SDL_Surface *texte;
  SDL_Surface *texte2;
  SDL_Surface *texte3;
  SDL_Event event;
  char str[18];
  char str1[18];
  t_info *i;

  i = init_info();
  i = resize_info(i);
  if (i == NULL)
    printf("NULL PAS INIT CACAC\n");
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  SDL_GetMouseState(&x, &y);
	  x = convertX(x, g);
	  y = convertX(y, g);
	  sprintf(str, "x: %d", x);
	  sprintf(str1, "y: %d", y);
	  drawImage(i->info, 1000, 0, g->screen);
	  texte = TTF_RenderText_Solid(i->police, "INFO", i->color);
	  texte2 = TTF_RenderText_Solid(i->police, str, i->color);
	  texte3 = TTF_RenderText_Solid(i->police, str1, i->color);
	  drawImage(texte, 1010, 10, g->screen);
	  drawImage(texte2, 1180, 10, g->screen);
	  drawImage(texte3, 1340, 10, g->screen);
	  drawFood(i, g);
	  SDL_FreeSurface(texte);
	  SDL_FreeSurface(texte2);
	  SDL_FreeSurface(texte3);
	}
      if (event.type == SDL_QUIT)
	{
	  SDL_FreeSurface(g->screen);
	  free_all_info(i);
	  free_all(g);
	  exit(0);
	}
    }
  TTF_CloseFont(i->police);
  free_all_info(i);
}
