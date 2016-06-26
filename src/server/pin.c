/*
** pin.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 13:22:42 2016 Loïc Weinhard
** Last update Sun Jun 26 13:48:22 2016 Loïc Weinhard
*/

#include "graphic_client.h"
#include "utils.h"
#include "xfct.h"

static char	*concat_primary_infos(t_client *player)
{
  int		*primary;
  char		*str;
  char		*tmp;
  int		i;

  i = 0;
  str = strdup("pin ");
  primary = &(player->fd);
  while (i < 3)
    {
      str = my_strcat(str, (tmp = itoa(*primary)));
      primary++;
      i += 1;
      i < 3 ? str = my_strcat(str, " ") : 0;
      xfree(tmp);
    }
  return (str);
}

static char	send_inventaire(t_client *player, t_graphic *graphic)
{
  char		*str;
  char		*tmp;
  int		i;
  int		*material;

  i = 0;
  material = &(player->materials.food);
  str = concat_primary_infos(player);
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
