/*
** clients.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:44:01 2016 Loïc Weinhard
** Last update Mon Jun 13 16:47:55 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "client.h"

void	free_clients(t_client *clients)
{
  while (clients != NULL)
    {
      xclose(clients->fd);
      if (clients->next != NULL)
	{
	  clients = clients->next;
	  xfree(clients->prev);
	}
      else
	xfree(clients);
    }
}
