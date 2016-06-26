/*
** inventaire.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sun Jun 26 10:08:15 2016 Aurelie Orset
** Last update Sun Jun 26 13:27:27 2016 Aurelie Orset
*/

#include "graphic.h"

void	drawInventPlayer(t_info *i, t_graph *g, char **tab)
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

void	drawInventaire(t_graph *g, t_client_socket client)
{
  char *str;
  char	**tab;
  int	id;
  t_info	*i;

  id = getID(client, g);
  i = init_info(g);
  i = resize_info(i, 0.2);
  if ((i->police = TTF_OpenFont("gfx/font.ttf", 35)) == NULL)
    printf("NO LOAD\n");
  str = xmalloc(sizeof(char) * 255);
  sprintf(str, "pin %d", id);
  str = send_and_get_gfx(&client, str);
  /*  str = "pin 36 56 56 0 1 2 3 4 5 6\n";*/
  tab = my_str_to_wordtab(str, " \n");
  printf("INVENTAIRE : %s\n", str);
  if (strcmp(tab[0], "sbp") != 0 && id != -1)
    {
      drawInventPlayer(i, g, tab);
    }
}
