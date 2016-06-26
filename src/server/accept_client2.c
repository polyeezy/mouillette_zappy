/*
** accept_client2.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy/src/server
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sun Jun 26 21:32:43 2016 Aurelie Orset
** Last update Sun Jun 26 21:35:11 2016 Aurelie Orset
*/

#include <time.h>
#include "team.h"
#include "server.h"
#include "xfct.h"

void	update_map(t_client **clients, t_client **new)
{
  t_client	*tmp;

  tmp = *clients;
  while (tmp && tmp->next_map && (tmp = tmp->next_map));
  (*new)->prev_map = (tmp != NULL ? tmp : NULL);
  (*new)->next_map = NULL;
  if (tmp == NULL)
    *clients = *new;
  else
    tmp->next_map = *new;
}

void	add_client_ext(t_server **server, t_client **clients, int fd)
{
  t_client	*tmp;
  t_client	*new;

  tmp = *clients;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = create_client(*server, fd);
  if (*clients == NULL)
    {
      *clients = new;
      (*clients)->prev = NULL;
    }
  else
    {
      tmp->next = new;
      new->prev = tmp;
    }
  update_map(&((*server)->map[new->y][new->x].players), &new);
}
