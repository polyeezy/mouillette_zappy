/*
** info.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 14:18:08 2016 Aurelie Orset
** Last update Thu Jun 23 12:52:10 2016 Aurelie Orset
*/

#include "graphic.h"

int	convertX(int x, t_graph *g)
{
  double calc;

  calc = (x / g->ts);
  x = calc;
  return (x+1);
}

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

void	drawFood(t_info *i, t_graph *g, TTF_Font *police)
{
  SDL_Surface *texte;
  SDL_Color color = {255,255,255};
  char str[15];

  sprintf(str, "%d", 122);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->l, 1050, 100, g->screen);
  drawImage(texte, 1150, 110, g->screen);
  sprintf(str, "%d", 213);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->d, 1250, 100, g->screen);
  drawImage(texte, 1350, 110, g->screen);
  sprintf(str, "%d", 2);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->s, 1050, 200, g->screen);
  drawImage(texte, 1150, 210, g->screen);
  sprintf(str, "%d", 2);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->m, 1250, 200, g->screen);
  drawImage(texte, 1350, 210, g->screen);
  sprintf(str, "%d", 2);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->p, 1050, 300, g->screen);
  drawImage(texte, 1150, 310, g->screen);
  sprintf(str, "%d", 2);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->t, 1250, 300, g->screen);
  drawImage(texte, 1350, 310, g->screen);
  sprintf(str, "%d", 2);
  texte = TTF_RenderText_Solid(police, str, color);
  drawImage(i->n, 1150, 400, g->screen);
  drawImage(texte, 1250, 410, g->screen);
}

void	drawInfo(int x, int y, t_graph *g)
{
  TTF_Font *police;
  SDL_Color color = {255,255,255};
  SDL_Surface *texte;
  SDL_Surface *texte2;
  SDL_Surface *texte3;
  SDL_Surface *player;
  SDL_Event event;
  char str[18];
  char str1[18];
  t_info *i;

  i = init_info();
  i = resize_info(i);
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  SDL_GetMouseState(&x, &y);
	  x = convertX(x, g);
	  y = convertX(y, g);
	  sprintf(str, "x: %d", x);
	  sprintf(str1, "y: %d", y);
	  if ((police = TTF_OpenFont("gfx/font.ttf", 55)) == NULL)
	    printf("no load\n");
	  drawImage(i->info, 1000, 0, g->screen);
	  player = loadImage("gfx/player.png");
	  texte = TTF_RenderText_Solid(police, "INFO", color);
	  texte2 = TTF_RenderText_Solid(police, str, color);
	  texte3 = TTF_RenderText_Solid(police, str1, color);
	  drawImage(texte, 1010, 10, g->screen);
	  drawImage(texte2, 1180, 10, g->screen);
	  drawImage(texte3, 1340, 10, g->screen);
	  drawFood(i, g, police);
	  TTF_CloseFont(police);
	  SDL_FreeSurface(texte);
	  SDL_FreeSurface(texte2);
	  SDL_FreeSurface(texte3);
	  SDL_FreeSurface(player);
	}
      if (event.type == SDL_QUIT)
	{
	  SDL_FreeSurface(g->screen);
	  free_all_info(i);
	  free_all(g);
	  exit(0);
	}
    }
  free_all_info(i);
}
