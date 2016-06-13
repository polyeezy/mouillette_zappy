/*
** main.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 10:45:12 2016 Loïc Weinhard
** Last update Mon Jun 13 15:09:04 2016 Loïc Weinhard
*/

#include <string.h>
#include <stdio.h>
#include "args.h"
#include "utils.h"

int	check_param(char **argv, int i)
{
  int	x;
  int	y;

  x = 0;
  while (x < SERVER_ARGS)
    {
      if (!g_server_args[x].used && strcmp(g_server_args[x].flag, argv[i]) == 0)
	{
	  y = 0;
	  g_server_args[x].used = 1;
	  i += 1;
	  while (y < g_server_args[x].number_of_args)
	    {
	      if (g_server_args[x].numeric_value && isitnum(argv[i]))
		return (-1);
	      i += 1;
	      y += 1;
	    }
	  return (i);
	}
      x += 1;
    }
  return (-1);
}

int	check_args(char **argv)
{
  int	i;

  i = 1;
  while (argv[i])
    {
      if ((i = check_param(argv, i)) == -1)
	return (-1);
    }
  i = 0;
  while (i < SERVER_ARGS)
    {
      if (g_server_args[i].mandatory && !g_server_args[i].used)
	return (-1);
      i += 1;
    }
  return (0);
}

int	print_usage()
{
  int	i;

  i = 0;
  dprintf(2, "Usage : zappy_server ");
  while (i < SERVER_ARGS)
    {
      dprintf(2, "%s %s ", g_server_args[i].flag, g_server_args[i].description);
      i += 1;
    }
  dprintf(2, "\n");
  return (-1);
}

int	main(int argc, char **argv)
{
  (void)argc;
  if (check_args(argv) == -1)
    return (print_usage());
  return (0);
}
