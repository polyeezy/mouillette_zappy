/*
** client.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:11:15 2016 Loïc Weinhard
** Last update Sat Jun 25 14:25:38 2016 Valerian Polizzi
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
# include <utils.h>
# include <stdio.h>
# include <string.h>
# include <ai_cmd.h>
# include "orientation.h"
# include "materials.h"


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
    JOINING_OTHER	=	3
  }			e_state;

typedef struct		s_ai
{
  size_t		lvl;
  char			*last_response;
  char			*team;
  t_client_socket	socket;
  e_state		state;
}			t_ai;

int             object_is_in_cell(char *cell, char *obj);
int             look_for_object(char **vision, char *to_find);
int             send_cmd_server(t_ai *cli, char *msg);
char            *get_server_response(t_ai *cli);
char		*send_and_get(t_ai *cli, char *cmd);
t_client	init_client(char **argv);
t_client_socket	init_client_socket(char **argv);
void		free_clients(t_client *clients);
char		**parse_voir(t_ai *cli);
void            debug_material(t_materials *inv);
t_materials	parse_inventaire(t_ai *cli);
void		ai_do_move(t_ai *cl, int f1, int d, int f2);
void		ai_count_move(t_ai *cl, int cell);

void            ai_avance(t_ai*);
void            ai_droite(t_ai*);
void            ai_gauche(t_ai*);
void            ai_voir(t_ai*);
void            ai_inventaire(t_ai*);
void            ai_prend(t_ai*, char*);
void            ai_pose(t_ai*, char*);
void            ai_expulse(t_ai*, char*);
void            ai_broadcast(t_ai*, char*);
void            ai_incantation(t_ai*, char*);
void            ai_fork(t_ai*, char*);
void            ai_connect_nbr(t_ai*);
void            ai_dead(t_ai*);
void		client_get_lvl1(t_ai *cli);
void		client_get_lvl2(t_ai *cli);
void		client_get_food(t_ai *cli);
void		get_rid(t_ai *cli, char **required);
int             is_in_inventary(t_ai *cli, char *obj);
void            go_get_object(t_ai*, char *obj);

#endif
