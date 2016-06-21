/*
** cmds.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:15:38 2016 Loïc Weinhard
** Last update Tue Jun 21 18:25:26 2016 Loïc Weinhard
*/

#ifndef CMDS_H_
# define CMDS_H_

# include "server.h"
# include "client.h"

# define NUMBER_OF_COMMANDS 4

typedef struct	s_cmd
{
  char		*name;
  char		*description;
  char		(*ptr_func)(t_server *, t_client *, char **);
}		t_cmd;

extern t_cmd	g_cmds[NUMBER_OF_COMMANDS];

void	handle_cmds(t_server *server, t_client *player);

char	droite(t_server *server, t_client *player, char **tab);
char	gauche(t_server *server, t_client *player, char **tab);
char	voir(t_server *server, t_client *player, char **tab);
char	inventaire(t_server *server, t_client *player, char **tab);

#endif
