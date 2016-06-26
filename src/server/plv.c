/*
** plv.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 13:12:30 2016 Loïc Weinhard
** Last update Sun Jun 26 13:19:47 2016 Loïc Weinhard
*/

#include "graphic_client.h"
#include "utils.h"
#include "xfct.h"

static char	send_level(t_client *player, t_graphic *graphic)
{
  char		*str;
  char		*tmp;

  str = xstrdup("plv ");
  str = my_strcat(str, (tmp = itoa(player->fd)));
  str = my_strcat(str, " ");
  xfree(tmp);
  str = my_strcat(str, (tmp = itoa(player->level)));
  str = my_strcat(str, "\n");
  xfree(tmp);
  xwrite(graphic->fd, str);
  xfree(str);
  return (0);
}

char		plv(t_server *server, t_graphic *graphic, char **tab)
{
  t_team	*team;
  t_client	*player;

  if (lentab(tab) != 2)
    {
      xwrite(graphic->fd, "sbp\n");
      return (0);
    }
  team = server->teams;
  while (team)
    {
      player = team->members;
      while (player)
	{
	  if (player->fd == atoi(tab[1]))
	    return (send_level(player, graphic));
	  player = player->next;
	}
      team = team->next;
    }
  xwrite(graphic->fd, "sbp\n");
  return (0);
}
