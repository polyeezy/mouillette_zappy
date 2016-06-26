
/*
** cmds.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:15:38 2016 Loïc Weinhard
** Last update Sun Jun 26 14:52:39 2016 Alexis Miele
*/

#ifndef CMDS_H_
# define CMDS_H_

# include <sys/time.h>
# include "server.h"
# include "client.h"

# define NUMBER_OF_COMMANDS 11

typedef struct s_server t_server;

typedef struct		s_cmd
{
  char			*name;
  char			*description;
  float			delay;
  void			(*pre_func)(t_server *, t_client *, char *, struct s_cmd *);
  char			(*post_func)(t_server *, t_client *, char **);
}			t_cmd;

extern t_cmd	g_cmds[NUMBER_OF_COMMANDS];

void		handle_cmds(t_server *server, t_client *player);

char		droite(t_server *server, t_client *player, char **tab);
char		gauche(t_server *server, t_client *player, char **tab);
char		voir(t_server *server, t_client *player, char **tab);
char		inventaire(t_server *server, t_client *player, char **tab);

char		avance(t_server *server, t_client *player, char **tab);
t_client	*relink(t_client *tmp, t_client *player);
void		add_player_on_map(t_client **player, t_client **new);

char		prend(t_server *server, t_client *player, char **tab);
char		pose(t_server *server, t_client *player, char **tab);
int		check_syntax(t_client *player, char **tab);

char		incantation(t_server *server, t_client *player, char **tab);
char		broadcast(t_server *server, t_client *player, char **tab);

char	        mange(t_server *server, t_client *player, char **tab);
char		connect_nbr(t_server *server, t_client *player, char **tab);

void		pre_droite(t_server *, t_client *, char *, t_cmd *);
void		pre_gauche(t_server *, t_client *, char *, t_cmd *);
void		pre_voir(t_server *, t_client *, char *, t_cmd *);
void		pre_inventaire(t_server *, t_client *, char *, t_cmd *);
void		pre_avance(t_server *, t_client *, char *, t_cmd *);
void		pre_prend(t_server *, t_client *, char *, t_cmd *);
void		pre_pose(t_server *, t_client *, char *, t_cmd *);
void		pre_incantation(t_server *, t_client *, char *, t_cmd *);
void		pre_broadcast(t_server *, t_client *, char *, t_cmd *);
void		pre_mange(t_server *, t_client *, char *, t_cmd *);
void		pre_connect_nbr(t_server *, t_client *, char *, t_cmd *);

#endif
