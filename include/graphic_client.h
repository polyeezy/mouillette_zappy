/*
** graphic_client.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 10:20:08 2016 Loïc Weinhard
** Last update Sun Jun 26 13:12:18 2016 Loïc Weinhard
*/

#ifndef GRAPHIC_CLIENT_H_
# define GRAPHIC_CLIENT_H_

# include "server.h"
# include "cmds.h"

# define NUMBER_OF_GRAPH_COMMANDS 3

typedef struct s_server t_server;

typedef struct		s_graphic
{
  int			fd;
  struct s_graphic	*next;
}			t_graphic;

typedef struct		s_graph_cmd
{
  char			*name;
  char			*description;
  char			(*ptr_func)(t_server *, t_graphic *, char **);
}			t_graph_cmd;

extern t_graph_cmd	g_graph_cmds[NUMBER_OF_GRAPH_COMMANDS];

void	add_graphic(t_server *server, t_graphic **graphic, int new_fd);
void	handle_graphics(t_server *server, t_graphic *graphic);

char	bct(t_server *server, t_graphic *graphic, char **tab);
char	lpy(t_server *server, t_graphic *graphic, char **tab);
char	plv(t_server *server, t_graphic *graphic, char **tab);

#endif
