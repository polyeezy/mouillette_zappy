/*
** info.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
**
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 14:18:08 2016 Aurelie Orset
** Last update Sun Jun 26 16:23:05 2016 Aurelie Orset
*/

#include "graphic.h"

void	drawPlayer(t_info *i, t_graph *g, t_client_socket client)
{
  char str[18];
  int	id;
  int lvl;

  id = getID(client, g);
  lvl = getLvl(client, id);
  printf("ID : %d\n", id);
  if (id != -1)
    {
      sprintf(str, " %d", id);
      drawTexte(i, 1015, 550, "PLAYER");
      drawTexte(i, 1200, 550, str);
      sprintf(str, " %d", lvl);
      drawTexte(i, 1015, 620, "LEVEL");
      drawTexte(i, 1200, 620, str);
      drawTexte(i, 1100, 690, "Inventaire");
    }
}

void	drawFood(t_info *i, int x, int y, t_client_socket client)
{
  char *str;
  char tmp[18];
  char	**tab;

  sprintf(tmp, "bct %d %d", x, y);
  str = send_and_get_gfx(&client, tmp);
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
  xfree(str);
  free_tab(tab);
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

void	drawInfo(int x, int y, t_graph *g, t_client_socket client)
{
  SDL_Event event;
  t_info *i;

  i = init_and_resize(g);
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  SDL_GetMouseState(&x, &y);
	  x = convertX(x, g);
	  y = convertX(y, g);
	  if ( x <= g->map_x && y <= g->map_y)
	    {
	      drawCoord(i, g, x, y);
	      drawFood(i, x, y, client);
	    }
	  drawPlayer(i, g, client);
	  drawInventaire(g, client);
	}
      else if (event.type == SDL_QUIT)
	free_at_exit(g, i);
    }
  free_all_info(i);
}
