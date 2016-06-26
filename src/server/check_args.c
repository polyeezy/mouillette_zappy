/*
** check_args.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:32:34 2016 Loïc Weinhard
** Last update Sun Jun 26 17:25:53 2016 Loïc Weinhard
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "utils.h"

static int	check_param(char **argv, int i)
{
  int		x;
  int		y;

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
	      if (g_server_args[x].numeric_value && (isitnum(argv[i]) ||
						     atoi(argv[i]) <= 0))
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

static int	print_usage()
{
  int		i;

  i = 0;
  dprintf(2, "Usage : zappy_server ");
  while (i < SERVER_ARGS)
    {
      if (g_server_args[i].mandatory)
	dprintf(2, "%s %s ", g_server_args[i].flag,
		g_server_args[i].description);
      else
	dprintf(2, "[%s %s] ", g_server_args[i].flag,
		g_server_args[i].description);
      i += 1;
    }
  dprintf(2, "\n");
  return (-1);
}

int	check_args(char **argv)
{
  int	i;

  i = 1;
  while (argv[i])
    {
      if ((i = check_param(argv, i)) == -1)
	return (print_usage());
    }
  i = 0;
  while (i < SERVER_ARGS)
    {
      if (g_server_args[i].mandatory && !g_server_args[i].used)
	return (print_usage());
      i += 1;
    }
  return (0);
}
