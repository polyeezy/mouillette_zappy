/*
** players.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 24 16:00:41 2016 Aurelie Orset
** Last update Sat Jun 25 13:51:30 2016 Aurelie Orset
*/

#include "graphic.h"

char	**getToParse(t_client_socket client)
{
  char **tab;
  char *str;

  str = xmalloc(sizeof(char) * 255);
  str = send_and_get_gfx(&client, "lpy");
  str = "lpy 4\n4 1 6 6 0\n3 2 7 7 0\n32 3 5 5 0\n56 4 4 4 1\n";
  tab = my_str_to_wordtab(str, " \n");
  return (tab);
}

void	drawOrient(t_graph *g, int x, char **tab)
{
  int mapx;
  int mapy;

  mapx = atoi(tab[x + 2]);
  mapy = atoi(tab[x + 3]);
  if (atoi(tab[x + 4]) == 1)
    drawImage(g->incant, mapx * g->ts, mapy * g->ts, g->screen);
  if (atoi(tab[x + 1]) == 2)
    drawImage(g->nord, mapx * g->ts, mapy * g->ts, g->screen);
  else if (atoi(tab[x + 1]) == 2)
    drawImage(g->est, mapx * g->ts, mapy * g->ts, g->screen);
  else if (atoi(tab[x + 1]) == 3)
    drawImage(g->sud, mapx * g->ts, mapy * g->ts, g->screen);
  else
    drawImage(g->ouest, mapx * g->ts, mapy * g->ts, g->screen);
}

void	drawPlayers(t_graph *g, t_client_socket client)
{
  char **tab;
  int	players;
  int	i;
  int	x;

  i = 0;
  x = 2;
  players = 0;
  tab = getToParse(client);
  if (strcmp(tab[0], "lpy") == 0)
    players = atoi(tab[1]);
  while (i < players)
    {
      drawOrient(g, x, tab);
      x+= 5;
      i++;
    }
}
