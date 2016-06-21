/*
** voir.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 15:48:55 2016 Loïc Weinhard
** Last update Mon Jun 20 21:34:19 2016 Loïc Weinhard
*/

#include "map.h"
#include "cmds.h"
#include "xfct.h"
#include "utils.h"

static char	nord(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;

  i = 0;
  dprintf(player.fd, "§");
  while (i <= player.level)
    {
      y = mod(player.y - i, server.height);
      x = mod(player.x - i, server.width);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
	  get_elems(player, server.map[y][x]);
	  x = mod(player.x + 1, server.width);
	  limit += 1;
          limit < (2 * i) + 1 ? dprintf(player.fd, ",") : 0;
	}
      i += 1;
      dprintf(player.fd, (i <= player.level ? "," : " §"));
    }
  return (0);
}

static char	est(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;

  i = 0;
  dprintf(player.fd, "§");
  while (i <= player.level)
    {
      x = mod(player.x + i, server.width);
      y = mod(player.y - i, server.height);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
          get_elems(player, server.map[y][x]);
          y = mod(player.y + 1, server.height);
	  limit += 1;
          limit < (2 * i) + 1 ? dprintf(player.fd, ",") : 0;
	}
      i += 1;
      dprintf(player.fd, (i <= player.level ? "," : " §"));
    }
  return (0);
}

static char	sud(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;

  i = 0;
  dprintf(player.fd, "§");
  while (i <= player.level)
    {
      y = mod(player.y + i, server.height);
      x = mod(player.x + i, server.width);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
          get_elems(player, server.map[y][x]);
          x = mod(player.x - 1, server.width);
	  limit += 1;
          limit < (2 * i) + 1 ? dprintf(player.fd, ",") : 0;
	}
      i += 1;
      dprintf(player.fd, (i <= player.level ? "," : " §"));
    }
  return (0);
}

static char	ouest(t_server server, t_client player)
{
  int		i;
  int		x;
  int		y;
  int		limit;

  i = 0;
  dprintf(player.fd, "§");
  while (i <= player.level)
    {
      x = mod(player.x - i, server.width);
      y = mod(player.y + i, server.height);
      limit = 0;
      while (limit < (2 * i) + 1)
	{
	  get_elems(player, server.map[y][x]);
	  y = mod(player.y - 1, server.height);
	  limit += 1;
	  limit < (2 * i) + 1 ? dprintf(player.fd, ",") : 0;
	}
      i += 1;
      dprintf(player.fd, (i <= player.level ? "," : " §"));
    }
  return (0);
}

char	voir(t_server *server, t_client *player, char **tab)
{
  char	(*ptr_func[4])(t_server, t_client);

  (void)tab;
  ptr_func[NORTH] = &nord;
  ptr_func[EAST] = &est;
  ptr_func[SOUTH] = &sud;
  ptr_func[WEST] = &ouest;
  ptr_func[player->orientation](*server, *player);
  return (0);
}
