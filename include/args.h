/*
** args.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 13:21:44 2016 Loïc Weinhard
** Last update Thu Jun 23 17:59:41 2016 Aurelie Orset
*/

#ifndef ARGS_H_
# define ARGS_H_

# include <string.h>

# define SERVER_ARGS	6
# define CLIENT_ARGS	3
# define GFX_ARGS	2

typedef struct	s_arg
{
  char		*flag;
  char		*description;
  int		number_of_args;
  char		more_or_not;
  char		numeric_value;
  char		mandatory;
  char		used;
}		t_arg;

int	check_args(char **argv);
int	get_arg(char **argv, char *arg);

extern t_arg	g_server_args[SERVER_ARGS];
extern t_arg	g_client_args[CLIENT_ARGS];
extern t_arg	g_gfx_args[GFX_ARGS];

#endif
