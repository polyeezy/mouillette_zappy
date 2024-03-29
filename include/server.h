/*
** server.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:09:23 2016 Loïc Weinhard
** Last update Sun Jun 26 21:36:50 2016 Aurelie Orset
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
# include "pile.h"
# include "graphic_client.h"

typedef struct s_pile t_pile;
typedef struct s_graphic t_graphic;

typedef struct 		s_server
{
  int			fd;
  int			fd_max;
  int			timeout;
  t_case		**map;
  int			width;
  int			height;
  t_team		*teams;
  t_pile		*pile;
  t_graphic		*graphic;
  struct sockaddr_in	client_addr;
  socklen_t		client_size;
  fd_set		readfds;
}			t_server;

t_server	init_server(char **argv);
void		accept_client(t_server *server);
void		remove_client(t_server *server, t_client *player, int ret);
int		close_server(t_server server);
void		calc_delay(t_pile *pile, struct timeval *delay);
void		update_map(t_client **clients, t_client **new);
void		add_client_ext(t_server **server, t_client **clients, int fd);
t_client	*create_client(t_server *server, int fd);

#endif
