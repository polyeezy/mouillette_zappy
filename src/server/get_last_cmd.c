/*
** get_last_command.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 19:08:50 2016 Loïc Weinhard
** Last update Sun Jun 26 19:57:16 2016 Loïc Weinhard
*/

#include "server.h"
#include "pile.h"
#include "utils.h"
#include "xfct.h"

time_t			get_last_command(t_server *server, t_client *player)
{
  t_pile		*pile;
  time_t		last;
  struct timeval	actual;

  gettimeofday(&actual, NULL);
  last = actual.tv_sec;
  pile = server->pile;
  while (pile)
    {
      if (pile->player && pile->player->fd == player->fd &&
	  strcmp(pile->cmd, "mange") != 0)
	last = pile->exec_time;
      pile = pile->next;
    }
  return (last);
}
