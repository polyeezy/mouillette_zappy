/*
** pile.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 24 14:08:45 2016 Loïc Weinhard
** Last update Sat Jun 25 19:34:08 2016 Loïc Weinhard
*/

#ifndef PILE_H_
# define PILE_H_

# include <sys/time.h>
# include "cmds.h"
# include "client.h"

typedef struct s_server t_server;
typedef struct s_cmd t_cmd;

typedef struct		s_pile
{
  char			*cmd;
  t_client		*player;
  time_t		exec_time;
  t_cmd			*func;
  struct s_pile		*next;
  struct s_pile		*prev;
}			t_pile;

void	add_pile(t_server *server, t_client *player, char *buff, t_cmd *cmd);
void	exec_pile(t_server *server, t_pile **pile);

#endif
