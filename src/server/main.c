/*
** main.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 10:45:12 2016 Loïc Weinhard
** Last update Tue Jun 14 13:54:00 2016 Loïc Weinhard
*/

#include "args.h"
#include "utils.h"
#include "server.h"
#include "sig.h"

extern char g_exit;

int		main(int argc, char **argv)
{
  t_server	server;

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  server = init_server(argv);
  signal(SIGINT, handle_sigint);
  while (g_exit != 1);
  close_server(server);
  return (0);
}
