/*
** graphic.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 10:42:01 2016 Loïc Weinhard
** Last update Sun Jun 26 10:53:33 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "graphic_client.h"

void		add_graphic(t_server *server, t_graphic **graphic, int new_fd)
{
  t_graphic	*tmp;
  t_graphic	*elem;

  elem = xmalloc(sizeof(t_graphic));
  dprintf(new_fd, "msz %d %d\n", server->width, server->height);
  elem->fd = new_fd;
  elem->next = NULL;
  if (*graphic == NULL)
    {
      *graphic = elem;
      return;
    }
  tmp = *graphic;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
}
