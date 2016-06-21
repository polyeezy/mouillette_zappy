/*
** client.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:11:15 2016 Loïc Weinhard
** Last update Tue Jun 21 16:31:50 2016 Valerian Polizzi
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <netinet/in.h>
# include "orientation.h"
# include "materials.h"
# include <stdio.h>
# include <string.h>

typedef struct		s_client
{
  int			fd;
  int			level;
  int			x;
  int			y;
  t_orientation		orientation;
  t_materials		materials;
  struct sockaddr_in	server_addr;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_client_socket
{
  int			fd;
  struct sockaddr_in	server_addr;
}			t_client_socket;

typedef enum		state
  {
    SURVIVOR		=	0,
    LOOKING_FOR		=	1,
    WAITING_OTHER	=	2,
    JOINING_OTHER	=	3,
  }			e_state;

typedef struct		s_ai
{
  size_t		lvl;
  char			*last_response;
  char			*team;
  t_client_socket	socket;
  e_state		state;
}			t_ai;


int		send_cmd_server(t_client_socket *cli, char *msg);
t_client	init_client(char **argv);
t_client_socket	init_client_socket(char **argv);
void		free_clients(t_client *clients);

#endif
