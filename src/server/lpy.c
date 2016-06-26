/*
** lpy.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 12:44:15 2016 Loïc Weinhard
** Last update Sun Jun 26 13:09:06 2016 Loïc Weinhard
*/

#include "graphic_client.h"
#include "utils.h"
#include "xfct.h"

static int	count_players(t_server *server)
{
  t_team	*team;
  t_client	*player;
  int		i;

  team = server->teams;
  i = 0;
  while (team)
    {
      player = team->members;
      while (player)
	{
	  i += 1;
	  player = player->next;
	}
      team = team->next;
    }
  return (i);
}

static char	*concat_info_player(t_client *player, int nb)
{
  char		*tmp;
  char		*str;

  str = NULL;
  str = my_strcat(str, (tmp = itoa(player->fd)));
  str = my_strcat(str, " ");
  xfree(tmp);
  str = my_strcat(str, (tmp = itoa(player->orientation + 1)));
  str = my_strcat(str, " ");
  xfree(tmp);
  str = my_strcat(str, (tmp = itoa(player->x)));
  str = my_strcat(str, " ");
  xfree(tmp);
  str = my_strcat(str, (tmp = itoa(player->y)));
  str = my_strcat(str, " ");
  xfree(tmp);
  str = my_strcat(str, "0");
  str = my_strcat(str, " ");
  str = my_strcat(str, (tmp = itoa(nb)));
  str = my_strcat(str, "\n");
  xfree(tmp);
  return (str);
}

static char	*get_each_player(t_server *server, char *str)
{
  t_team	*team;
  t_client	*player;
  int		nb;

  team = server->teams;
  nb = 0;
  while (team)
    {
      player = team->members;
      while (player)
	{
	  str = my_strcat(str, concat_info_player(player, nb));
	  player = player->next;
	}
      nb += 1;
      team = team->next;
    }
  return (str);
}

char	lpy(t_server *server, t_graphic *graphic, char **tab)
{
  char	*str;
  char	*count;

  if (lentab(tab) != 1)
    {
      xwrite(graphic->fd, "sbp\n");
      return (0);
    }
  str = strdup("lpy ");
  str = my_strcat(str, (count = itoa(count_players(server))));
  str = my_strcat(str, "\n");
  str = get_each_player(server, str);
  xwrite(graphic->fd, str);
  xfree(str);
  return (0);
}
