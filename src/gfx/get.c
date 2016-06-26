/*
** get.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sat Jun 25 13:54:42 2016 Aurelie Orset
** Last update Sun Jun 26 17:03:51 2016 Aurelie Orset
*/

#include "graphic.h"

char	**init_id_tab(t_client_socket client)
{
  char	*str;
  char **tab;

  str = send_and_get_gfx(&client, "lpy");
  tab = my_str_to_wordtab(str, " \n");
  xfree(str);
  return (tab);
}

int	compareID(int l, int x, int y, char **tab)
{
  int	mapx;
  int	mapy;

  mapx = atoi(tab[l + 2]);
  mapy = atoi(tab[l + 3]);
  if (mapx == x && mapy == y)
    return (atoi(tab[l]));
  return (-1);
}

int	getID(t_client_socket client, t_graph *g)
{
  t_coord c;
  int	players;
  char	**tab;
  int	i;
  int	l;

  l = 2;
  i = 0;
  players = 0;
  c.lvl = -1;
  c.id = -1;
  tab = init_id_tab(client);
  if (strcmp(tab[0], "lpy") == 0)
    players = atoi(tab[1]);
  SDL_GetMouseState(&c.x, &c.y);
  c.x = convertX(c.x, g);
  c.y = convertX(c.y, g);
  while (i++ < players)
    {
      printf("%d\n", i);
      if (compareID(l, c.x, c.y, tab) != -1 && getLvl(client, (compareID(l, c.x, c.y, tab)) > c.lvl))
	{
	  c.lvl = getLvl(client, compareID(l, c.x, c.y, tab));
	  c.id = compareID(l, c.x, c.y, tab);
	}
      l+=6;
    }
  free_tab(tab);
  return (c.id);
}

int	getLvl(t_client_socket client, int id)
{
  char	*str;
  char tmp[18];
  char	**tab;
  int	lvl;

  sprintf(tmp, "plv %d", id);
  str = send_and_get_gfx(&client, tmp);
  printf("LEVEL GET %s\n", str);
  tab = my_str_to_wordtab(str, " \n");
  if (strcmp(tab[0], "sbp") == 0)
    {
      xfree(str);
      free_tab(tab);
      return (-1);
    }
  lvl = atoi(tab[2]);
  free_tab(tab);
  xfree(str);
  return (lvl);
}
