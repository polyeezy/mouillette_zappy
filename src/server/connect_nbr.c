/*
** connect_nbr.c for connect_nbr in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 14:43:25 2016 Alexis Miele
** Last update Sun Jun 26 19:51:05 2016 Loïc Weinhard
*/

#include "cmds.h"
#include "xfct.h"

static char	*create_str(int nb)
{
  char		*str;

  str = itoa(nb);
  str = my_strcat(str, "\n");
  return (str);
}

char		connect_nbr(t_server *server, t_client *player, char **tab)
{
  int		i;
  int		st;
  t_team	*teams;
  t_client	*tmp;
  char		*str;

  (void)tab;
  st = 0;
  teams = server->teams;
  while (teams && st != 1)
    {
      i = 0;
      tmp = teams->members;
      while (tmp)
	{
	  tmp->fd == player->fd ? st = 1 : 0;
	  i += 1;
	  tmp = tmp->next;
	}
      teams = teams->next;
    }
  str = create_str(server->teams->max - i);
  xwrite(player->fd, str);
  xfree(str);
  return (0);
}
