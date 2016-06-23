/*
** check_args.c for check args in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Tue Jun 14 18:47:22 2016 Alexis Miele
** Last update Thu Jun 23 17:59:07 2016 Aurelie Orset
*/

#include <string.h>
#include <stdio.h>
#include "args.h"
#include "utils.h"

static int	check_param(char **argv, int i)
{
  int		x;
  int		y;

  x = 0;
  while (x < GFX_ARGS)
    {
      if (!g_gfx_args[x].used && strcmp(g_gfx_args[x].flag, argv[i]) == 0)
	{
	  y = 0;
	  g_gfx_args[x].used = 1;
	  i += 1;
	  while (y < g_gfx_args[x].number_of_args)
	    {
	      if (g_gfx_args[x].numeric_value && isitnum(argv[i]))
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
  dprintf(2, "Usage : zappy_gfx ");
  while (i < GFX_ARGS)
    {
      if (g_gfx_args[i].mandatory)
	dprintf(2, "%s %s ", g_gfx_args[i].flag, g_gfx_args[i].description);
      else
	dprintf(2, "[%s %s] ", g_gfx_args[i].flag, g_gfx_args[i].description);
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
  while (i < GFX_ARGS)
    {
      if (g_gfx_args[i].mandatory && !g_gfx_args[i].used)
	return (print_usage());
      i += 1;
    }
  return (0);
}
