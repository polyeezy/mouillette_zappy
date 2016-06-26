/*
** graphic.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 10:42:01 2016 Loïc Weinhard
** Last update Sun Jun 26 11:26:29 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "graphic_client.h"

void		handle_graphics(t_server *server, t_graphic *graphic)
{
  char	buffer[4097];
  int	ret;
  char	**tab;
  int	i;

  i = 0;
  ret = xread(graphic->fd, buffer, 4096);
  if (ret == 0 || ret == 1)
    {
      //remove_graphic(server, graphic, ret);
      return;
    }
  buffer[ret] = 0;
  printf("Graphic %d sent : [%.*s]\n", graphic->fd,
	 my_strlen(buffer) - 1, buffer);
  tab = my_str_to_wordtab(buffer, " \t\r\n");
  while (i < NUMBER_OF_GRAPH_COMMANDS)
    {
      if (strcmp(g_graph_cmds[i].name, tab[0]) == 0)
	g_graph_cmds[i].ptr_func(server, graphic, tab);
      i += 1;
    }
  free_tab(tab);
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
      *graphic = elem;
      return;
    }
  tmp = *graphic;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
}
