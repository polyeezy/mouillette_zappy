/*
** voir.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 15:48:55 2016 Loïc Weinhard
** Last update Thu Jun 23 15:01:14 2016 Loïc Weinhard
*/

#include "map.h"
#include "cmds.h"
#include "xfct.h"
#include "utils.h"

static char	*nord(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;
  char		*str;

  i = 0;
  str = strdup("{");
  while (i <= player.level)
    {
      y = mod(player.y - i, server.height);
      x = mod(player.x - i, server.width);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
	  str = my_strcat(str, get_elems(server.map[y][x]));
	  x = mod(x + 1, server.width);
	  limit += 1;
          limit < (2 * i) + 1 ? str = my_strcat(str, ",") : 0;
	}
      i += 1;
      str = my_strcat(str, (i <= player.level ? "," : " }"));
    }
  str = my_strcat(str, "\n");
  return (str);
}

static char	*est(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;
  char		*str;

  i = 0;
  str = strdup("{");
  while (i <= player.level)
    {
      x = mod(player.x + i, server.width);
      y = mod(player.y - i, server.height);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
          str = my_strcat(str, get_elems(server.map[y][x]));
          y = mod(y + 1, server.height);
	  limit += 1;
          limit < (2 * i) + 1 ? str = my_strcat(str, ",") : 0;
	}
      i += 1;
      str = my_strcat(str, (i <= player.level ? "," : " }"));
    }
  str = my_strcat(str, "\n");
  return (str);
}

static char	*sud(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;
  char		*str;

  i = 0;
  str = strdup("{");
  while (i <= player.level)
    {
      y = mod(player.y + i, server.height);
      x = mod(player.x + i, server.width);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
          str = my_strcat(str, get_elems(server.map[y][x]));
          x = mod(x - 1, server.width);
	  limit += 1;
          limit < (2 * i) + 1 ? str = my_strcat(str, ",") : 0;
	}
      i += 1;
      str = my_strcat(str, (i <= player.level ? "," : " }"));
    }
  str = my_strcat(str, "\n");
  return (str);
}

static char	*ouest(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;
  char		*str;

  i = 0;
  str = strdup("{");
  while (i <= player.level)
    {
      x = mod(player.x - i, server.width);
      y = mod(player.y + i, server.height);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
	  str = my_strcat(str, get_elems(server.map[y][x]));
	  y = mod(y - 1, server.height);
	  limit += 1;
          limit < (2 * i) + 1 ? str = my_strcat(str, ",") : 0;
	}
      i += 1;
      str = my_strcat(str, (i <= player.level ? "," : " }"));
    }
  str = my_strcat(str, "\n");
  return (str);
}

char	voir(t_server *server, t_client *player, char **tab)
{
  char	*(*ptr_func[4])(t_server, t_client);
  char	*str;

  (void)tab;
  ptr_func[NORTH] = &nord;
  ptr_func[EAST] = &est;
  ptr_func[SOUTH] = &sud;
  ptr_func[WEST] = &ouest;
  str = ptr_func[player->orientation](*server, *player);
  xwrite(player->fd, str);
  xfree(str);
  return (0);
}
