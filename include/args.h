/*
** args.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 13:21:44 2016 Loïc Weinhard
** Last update Mon Jun 13 14:20:27 2016 Loïc Weinhard
*/

#ifndef ARGS_H_
# define ARGS_H_

# define SERVER_ARGS	6

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

extern t_arg	g_server_args[SERVER_ARGS];

#endif
