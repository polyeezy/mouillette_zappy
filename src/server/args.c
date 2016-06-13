/*
** args.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 13:28:54 2016 Loïc Weinhard
** Last update Mon Jun 13 14:40:51 2016 Loïc Weinhard
*/

#include "args.h"

t_arg	g_server_args[SERVER_ARGS] =
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
      "-x",
      "world's width",
      1,
      0,
      1,
      1,
      0
    },
    {
      "-y",
      "world's height",
      1,
      0,
      1,
      1,
      0
    },
    {
      "-n",
      "teams' name",
      2,
      1,
      0,
      1,
      0
    },
    {
      "-c",
      "maximum members allowed per team",
      1,
      0,
      1,
      1,
      0
    },
    {
      "-t",
      "delay per action",
      1,
      0,
      1,
      1,
      0
    }
};
