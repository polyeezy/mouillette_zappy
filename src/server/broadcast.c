/*
** broadcast.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 17:39:03 2016 Loïc Weinhard
** Last update Thu Jun 23 14:25:56 2016 Loïc Weinhard
*/

#include "cmds.h"

static char	send_message(t_client *player, t_client *dest, char **tab)
{
  (void)player;
  (void)dest;
  (void)tab;
  return (0);
}

char		broadcast(t_server *server, t_client *player, char **tab)
{
  t_team	*team;

  team = server->teams;
  while (team)
    {
      while (team->members)
	{
	  send_message(player, team->members, tab);
	  team->members = team->members->next;
	}
      team = server->teams->next;
    }
  dprintf(player->fd, "ok\n");
  return (0);
}
