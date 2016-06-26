/*
** get.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/gfx
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sat Jun 25 13:54:42 2016 Aurelie Orset
** Last update Sat Jun 25 16:39:11 2016 Aurelie Orset
*/

#include "graphic.h"

char	**init_id_tab(t_client_socket client)
{
  char	*str;
  char **tab;

  str = xmalloc(sizeof(char) * 4096);
  str = send_and_get_gfx(&client, "lpy");
  str = "lpy 4\n4 1 6 6 0\n3 2 7 7 0\n32 3 5 5 0\n56 4 4 4 1\n";
  tab = my_str_to_wordtab(str, " \n");
  return (tab);
}

int	compareID(int l, int x, int y, char **tab)
{
  int	mapx;
  int	mapy;

  mapx = atoi(tab[l + 2]);
  mapy = atoi(tab[l + 3]);
  if (mapx == x && mapy == y)
    {
      /*free_tab(tab);*/
      return (atoi(tab[l]));
    }
  /*  free_tab(tab);*/
  return (-1);
}

int	getID(t_client_socket client, t_graph *g)
{
  int	x;
  int	y;
  int	players;
  char	**tab;
  int	i;
  int	l;

  l = 2;
  i = 0;
  players = 0;
  tab = init_id_tab(client);
  if (strcmp(tab[0], "lpy") == 0)
    players = atoi(tab[1]);
  SDL_GetMouseState(&x, &y);
  x = convertX(x, g);
  y = convertX(y, g);
  while (i < players)
    {
      if (compareID(l, x, y, tab) != -1)
	{
	  /*	  free_tab(tab);*/
	  return (compareID(l, x, y, tab));
	}
      i++;
      l+=5;
    }
  /*  free_tab(tab);*/
  return (-1);
}

int	getLvl(t_client_socket client, int id)
{
  char	*str;
  char	**tab;
  int	lvl;

  str = xmalloc(sizeof(char) * 255);
  sprintf(str, "plv %d", id);
  str = send_and_get_gfx(&client, str);
  printf("LEVEL GET %s\n", str);
  tab = my_str_to_wordtab(str, " \n");
  if (strcmp(tab[0], "sbp") == 0)
    {
      xfree(str);
      free_tab(tab);
      return (-1);
    }
  lvl = atoi(tab[2]);
  xfree(str);
  /*free_tab(tab);*/
  return (lvl);
}