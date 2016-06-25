/*
** pile.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 24 14:57:02 2016 Loïc Weinhard
** Last update Fri Jun 24 15:55:24 2016 Loïc Weinhard
*/

#include "pile.h"
#include "xfct.h"

void			add_pile(t_server *server,
			 t_client *player, char *buff, t_cmd cmd)
{
  t_pile		*tmp;
  t_pile		*elem;
  struct timeval	actual;

  gettimeofday(&actual, NULL);
  elem = xmalloc(sizeof(t_pile));
  elem->cmd = buff;
  elem->player = player;
  elem->exec_time = actual.tv_sec + (cmd.delay * (1 / server->timeout));
  tmp = server->pile;
  if (tmp == NULL)
    {
      printf("La pile est vide.\n");
      elem->next = NULL;
      elem->prev = NULL;
      server->pile = elem;
      return;
    }
  while (tmp->next && elem->exec_time > tmp->exec_time)
    tmp = tmp->next;
  elem->prev = tmp->prev;
  elem->next = tmp;
  tmp->prev != NULL ? tmp->prev->next = elem : 0;
  tmp->prev = elem;
  while (tmp->prev && (tmp = tmp->prev));
  server->pile = tmp;
}
