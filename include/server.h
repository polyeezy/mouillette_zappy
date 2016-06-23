/*
** server.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:09:23 2016 Loïc Weinhard
** Last update Thu Jun 23 17:24:58 2016 Loïc Weinhard
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <netinet/in.h>
# include <string.h>
# include "team.h"
# include "map.h"

typedef struct 		s_server
{
  int			fd;
  int			fd_max;
  int			timeout;
  t_case		**map;
  int			width;
  int			height;
  t_team		*teams;
  struct sockaddr_in	client_addr;
  socklen_t		client_size;
  fd_set		readfds;
}			t_server;

t_server	init_server(char **argv);
void		accept_client(t_server *server);
void		remove_client(t_server *server, t_client *player, int ret);
void		close_server(t_server server);

#endif
