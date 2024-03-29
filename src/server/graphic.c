/*
** graphic.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 10:42:01 2016 Loïc Weinhard
** Last update Sun Jun 26 15:06:01 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "utils.h"
#include "graphic_client.h"

void		remove_graphic(t_graphic **graphic, int ret, t_server **server)
{
  if (ret != 0)
    return;
  xclose((*graphic)->fd);
  if ((*graphic)->prev == NULL && (*graphic)->next == NULL)
    {
      xfree(*graphic);
      *graphic = NULL;
      (*server)->graphic = NULL;
    }
  else if ((*graphic)->prev == NULL && (*graphic)->next != NULL)
    {
      (*graphic)->next->prev = NULL;
      (*server)->graphic = (*graphic)->next;
      xfree(*graphic);
      *graphic = NULL;
    }
  else
    {
      (*graphic)->prev->next = (*graphic)->next;
      (*graphic)->next != NULL ? (*graphic)->next->prev = (*graphic)->prev : 0;
      xfree(*graphic);
      *graphic = NULL;
    }
}

void	handle_graphics(t_server *server, t_graphic *graphic)
{
  char	buff[4097];
  int	ret;
  char	**tab;
  int	i;
  int	done;

  i = 0;
  done = 0;
  ret = xread(graphic->fd, buff, 4096);
  if (ret == 0 || ret == 1)
    {
      remove_graphic(&graphic, ret, &server);
      return;
    }
  buff[ret] = 0;
  printf("Graphic %d sent : [%.*s]\n", graphic->fd, my_strlen(buff) - 1, buff);
  tab = my_str_to_wordtab(buff, " \t\r\n");
  while (i < NUMBER_OF_GRAPH_COMMANDS)
    {
      if (strcmp(g_graph_cmds[i].name, tab[0]) == 0 && (done = 1))
	g_graph_cmds[i].ptr_func(server, graphic, tab);
      i += 1;
    }
  free_tab(tab);
  done != 1 ? xwrite(graphic->fd, "suc\n") : 0;
}

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
      elem->prev = NULL;
      *graphic = elem;
      return;
    }
  tmp = *graphic;
  while (tmp->next)
    tmp = tmp->next;
  elem->prev = tmp;
  tmp->next = elem;
}
