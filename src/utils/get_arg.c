/*
** get_arg.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:43:03 2016 Loïc Weinhard
** Last update Mon Jun 13 15:57:44 2016 Loïc Weinhard
*/

#include "args.h"

int	get_arg(char **argv, char *arg)
{
  int	i;

  i = 0;
  while (argv[i])
    {
      if (strcmp(argv[i], arg) == 0)
	return (i);
      i += 1;
    }
  return (-1);
}
