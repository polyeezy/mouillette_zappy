/*
** args.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 13:21:44 2016 Loïc Weinhard
** Last update Tue Jun 14 17:26:03 2016 Alexis Miele
*/

#ifndef ARGS_H_
# define ARGS_H_

# include <string.h>

# define SERVER_ARGS	6
# define CLIENT_ARGS	3

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

#endif
