/*
** info.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
**
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 14:18:08 2016 Aurelie Orset
** Last update Fri Jun 24 16:01:10 2016 Aurelie Orset
*/

#include "graphic.h"

int	convertX(int x, t_graph *g)
{
  double calc;

  calc = (x / g->ts);
  x = calc;
  return (x);
}

void	drawTexte(t_info *i, int x, int y, char *str)
{
  SDL_Surface *texte;

  texte = TTF_RenderText_Solid(i->police, str, i->color);
  drawImage(texte, x, y, i->screen);
  SDL_FreeSurface(texte);
}

void	drawInventaire(t_graph *g, int id, t_client_socket client)
{
  char *str;
  char	**tab;

  t_info	*i;

  i = init_info(g);
  i = resize_info(i, 0.2);
  if ((i->police = TTF_OpenFont("gfx/font.ttf", 35)) == NULL)
    printf("NO LOAD\n");
  str = malloc(sizeof(char) * 255);
  sprintf(str, "pin %d", id);
  str = send_and_get_gfx(&client, str);
  tab = my_str_to_wordtab(str, " \n");
  printf("INVENTAIRE : %s\n", str);
  if (strcmp(tab[0], "sbp") != 0)
    {
      drawImage(i->l, 1050, 750, g->screen);
      drawTexte(i, 1100, 750, tab[5]);
      drawImage(i->d, 1200, 750, g->screen);
      drawTexte(i, 1250, 750, tab[6]);
      drawImage(i->s, 1350, 750, g->screen);
      drawTexte(i, 1400, 750, tab[7]);
      drawImage(i->m, 1050, 810, g->screen);
      drawTexte(i, 1100, 810, tab[8]);
      drawImage(i->p, 1200, 810, g->screen);
      drawTexte(i, 1250, 810, tab[9]);
      drawImage(i->t, 1350, 810, g->screen);
      drawTexte(i, 1400, 810, tab[10]);
      drawImage(i->n, 1200, 870, g->screen);
      drawTexte(i, 1250, 870, tab[4]);
    }
  free(str);
}

void	drawPlayer(t_info *i, t_graph *g, int id, int lvl)
{
  SDL_Surface *texte;
  SDL_Surface *texte2;
  char str[18];

  sprintf(str, " %d", id);
  texte = TTF_RenderText_Solid(i->police, "PLAYER", i->color);
  texte2 = TTF_RenderText_Solid(i->police, str, i->color);
  drawImage(texte, 1015, 550, g->screen);
  drawImage(texte2, 1200, 550, g->screen);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
  sprintf(str, " %d", lvl);
  texte = TTF_RenderText_Solid(i->police, "LEVEL", i->color);
  texte2 = TTF_RenderText_Solid(i->police, str, i->color);
  drawImage(texte, 1015, 620, g->screen);
  drawImage(texte2, 1200, 620, g->screen);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
  texte = TTF_RenderText_Solid(i->police, "Inventaire", i->color);
  drawImage(texte, 1100, 690, g->screen);
  SDL_FreeSurface(texte);
}

void	drawFood(t_info *i, int x, int y, t_client_socket client)
{
  char *str;
  char	**tab;

  str = malloc(sizeof(char) * 255);
  sprintf(str, "bct %d %d", x, y);
  str = send_and_get_gfx(&client, str);
  tab = my_str_to_wordtab(str, " \n");
  printf("FOOD REQUEST %s\n", str);
  drawImage(i->l, 1050, 100, i->screen);
  drawTexte(i, 1150, 110, tab[4]);
  drawImage(i->d, 1250, 100, i->screen);
  drawTexte(i, 1350, 110, tab[5]);
  drawImage(i->s, 1050, 200, i->screen);
  drawTexte(i, 1150, 210, tab[6]);
  drawImage(i->m, 1250, 200, i->screen);
  drawTexte(i, 1350, 210, tab[7]);
  drawImage(i->p, 1050, 300, i->screen);
  drawTexte(i, 1150, 310, tab[8]);
  drawImage(i->t, 1250, 300, i->screen);
  drawTexte(i, 1350, 310, tab[9]);
  drawImage(i->n, 1150, 400, i->screen);
  drawTexte(i, 1250, 410, tab[3]);
  free(str);
}

void	drawCoord(t_info *i, t_graph *g, int x, int y)
{
  SDL_Surface *texte;
  SDL_Surface *texte2;
  SDL_Surface *texte3;
  char str[18];
  char str1[18];

  sprintf(str, "x: %d", x);
  sprintf(str1, "y: %d", y);
  drawImage(i->info, 1000, 0, g->screen);
  texte = TTF_RenderText_Solid(i->police, "INFO", i->color);
  texte2 = TTF_RenderText_Solid(i->police, str, i->color);
  texte3 = TTF_RenderText_Solid(i->police, str1, i->color);
  drawImage(texte, 1010, 10, g->screen);
  drawImage(texte2, 1180, 10, g->screen);
  drawImage(texte3, 1340, 10, g->screen);
  SDL_FreeSurface(texte);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(texte3);
}

int	getLvl(t_client_socket client, int id)
{
  char	*str;
  char	**tab;
  int	lvl;

  str = malloc(sizeof(char) * 255);
  sprintf(str, "plv %d", id);
  str = send_and_get_gfx(&client, str);
  printf("LEVEL GET %s\n", str);
  tab = my_str_to_wordtab(str, " \n");
  if (strcmp(tab[0], "sbp") == 0)
    return (-1);
  lvl = atoi(tab[2]);
  free(str);
  return (lvl);
}

void	drawInfo(int x, int y, t_graph *g, t_client_socket client)
{
  SDL_Event event;
  t_info *i;
  int	id;
  int	lvl;

  id = 2;
  i = init_info(g);
  i = resize_info(i, 0.5);
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  lvl = getLvl(client, id);
	  SDL_GetMouseState(&x, &y);
	  x = convertX(x, g);
	  y = convertX(y, g);
	  if ( x <= g->map_x && y <= g->map_y)
	    {
	      drawCoord(i, g, x, y);
	      drawFood(i, x, y, client);
	    }
	  drawPlayer(i, g, id, lvl);
	  drawInventaire(g, id, client);
	}
      else if (event.type == SDL_QUIT)
	{
	  SDL_FreeSurface(g->screen);
	  free_all_info(i);
	  free_all(g);
	  exit(0);
	}
    }
  free_all_info(i);
}
