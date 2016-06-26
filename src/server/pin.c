/*
** pin.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 13:22:42 2016 Loïc Weinhard
** Last update Sun Jun 26 13:29:31 2016 Loïc Weinhard
*/

#include "graphic_client.h"
#include "utils.h"
#include "xfct.h"

static char	send_inventaire(t_client *player, t_graphic *graphic)
{
  char		*str;
  char		*tmp;
  int		i;
  int		*material;

  str = strdup("pin ");
  str = my_strcat(str, (tmp = itoa(player->fd)));
  xfree(tmp);
  i = 0;
  material = &(player->materials.food);
  while (i < 7)
    {
      str = my_strcat(str, " ");
      str = my_strcat(str, (tmp = itoa(*material)));
      xfree(tmp);
      material++;
      i += 1;
    }
  str = my_strcat(str, "\n");
  xwrite(graphic->fd, str);
  xfree(str);
  return (0);
}

char		pin(t_server *server, t_graphic *graphic, char **tab)
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
	    return (send_inventaire(player, graphic));
	  player = player->next;
	}
      team = team->next;
    }
  xwrite(graphic->fd, "sbp\n");
  return (0);
}
