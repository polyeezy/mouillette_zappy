/*
** args.c for args in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Tue Jun 14 17:29:18 2016 Alexis Miele
** Last update Tue Jun 14 18:55:19 2016 Alexis Miele
*/

#include "args.h"

t_arg	g_client_args[CLIENT_ARGS] =
{
    {
      "-n",
      "team's name",
      1,
      0,
      0,
      1,
      0
    },
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
