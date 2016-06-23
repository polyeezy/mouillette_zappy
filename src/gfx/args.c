/*
** args.c for args in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Tue Jun 14 17:29:18 2016 Alexis Miele
** Last update Thu Jun 23 18:00:57 2016 Aurelie Orset
*/

#include "args.h"

t_arg	g_gfx_args[GFX_ARGS] =
{
    {
      "-p",
      "port number",
      1,
      0,
      1,
      1,
      0
    },
    {
      "-h",
      "computer's name",
      1,
      0,
      0,
      0,
      0
    }
};
