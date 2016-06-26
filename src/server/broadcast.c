/*
** broadcast.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 17:39:03 2016 Loïc Weinhard
** Last update Thu Jun 23 20:54:08 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "utils.h"
#include "cmds.h"

static char	*get_dir(t_client *dest, int orientation)
{
  int		i;
  int		find;
  char		*str;

  find = 1;
  i = dest->orientation;
  str = NULL;
  while (str == NULL)
    {
      if (i == orientation)
	str = itoa(find);
      i = (i == 0 ? 3 : i - 1);
      find += 2;
    }
  return (str);
}

static int	check_vertical(int height, t_client *player, t_client *dest)
{
  int		haut;
  int		bas;

  if (dest->y > player->y)
    {
      haut = dest->y - player->y;
      bas = player->y + height - dest->y;
    }
  else
    {
      bas = player->y - dest->y;
      haut = height - player->y + dest->y;
    }
  if (haut < bas)
    return (SOUTH);
  else
    return (NORTH);
}

static int	check_horizontal(int width, t_client *player, t_client *dest)
{
  int		droite;
  int		gauche;

  if (dest->x > player->x)
    {
      droite = dest->x - player->x;
      gauche = player->x + width - dest->x;
    }
  else
    {
      gauche = player->x - dest->x;
      droite = width - player->x + dest->x;
    }
  if (droite < gauche)
    return (WEST);
  else
    return (EAST);
}

static char	send_message(t_server *server,
			     t_client *player, t_client *dest, char **tab)
{
  char		*orientation;
  char		*msg;
  int		i;

  (void)tab;
  i = 1;
  if (player->y == dest->y)
    orientation = get_dir(dest, check_horizontal(server->width, player, dest));
  else
    orientation = get_dir(dest, check_vertical(server->height, player, dest));
  msg = xstrdup("message ");
  msg = my_strcat(msg, orientation);
  msg = my_strcat(msg, ",");
  while (tab[i])
    {
      msg = my_strcat(msg, tab[i++]);
      tab[i] != NULL ? msg = my_strcat(msg, " ") : 0;
    }
  msg = my_strcat(msg, "\n");
  xwrite(dest->fd, msg);
  xfree(orientation);
  xfree(msg);
  return (0);
}

char		broadcast(t_server *server, t_client *player, char **tab)
{
  t_team	*team;
  t_client	*dest;

  team = server->teams;
  while (team)
    {
      dest = team->members;
      while (dest)
	{
	  dest->fd != player->fd ?
	      send_message(server, player, dest, tab) : 0;
	  dest = dest->next;
	}
      team = team->next;
    }
  xwrite(player->fd, "ok\n");
  return (0);
}
