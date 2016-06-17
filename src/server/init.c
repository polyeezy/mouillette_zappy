/*
** init.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:30:16 2016 Loïc Weinhard
** Last update Fri Jun 17 14:30:15 2016 Loïc Weinhard
*/

#include <time.h>
#include "args.h"
#include "xfct.h"
#include "server.h"
#include "network.h"

static void		init_case(t_case *acase)
{
  srand(time(NULL));
  acase->players = NULL;
  acase->materials.linemate = rand() % 21;
  acase->materials.deraumere = rand() % 21;
  acase->materials.sibur = rand() % 21;
  acase->materials.mendiane = rand() % 21;
  acase->materials.phiras = rand() % 21;
  acase->materials.thystame = rand() % 21;
}

static t_case		**init_map(char **argv)
{
  t_case		**map;
  int			i;
  int			x;

  map = xmalloc((atoi(argv[get_arg(argv, "-y") + 1]) + 1) * sizeof(t_case *));
  i = 0;
  while (i < atoi(argv[get_arg(argv, "-y") + 1]))
    {
      map[i] = xmalloc((atoi(argv[get_arg(argv, "-x") + 1])) * sizeof(t_case));
      x = 0;
      while (x < atoi(argv[get_arg(argv, "-x") + 1]))
	init_case(&(map[i][x++]));
      i += 1;
    }
  map[i] = NULL;
  return (map);
}

t_server		init_server(char **argv)
{
  t_server		server;
  int			port;

  port = atoi(argv[get_arg(argv, "-p") + 1]);
  server.fd = xsocket(DOMAIN, TYPE, xgetprotobyname(PROTOCOL));
  server.fd_max = server.fd + 1;
  server.timeout = atoi(argv[get_arg(argv, "-t") + 1]);
  server.teams = NULL;
  server.client_addr.sin_family = DOMAIN;
  server.client_addr.sin_port = xhtons(server.fd, port);
  server.map = init_map(argv);
  server.width = atoi(argv[get_arg(argv, "-x") + 1]);
  server.height = atoi(argv[get_arg(argv, "-y") + 1]);
  add_teams(&(server.teams), argv);
  server.client_addr.sin_addr.s_addr = ADDRESSES;
  server.client_size = sizeof(server.client_addr);
  xbind(server.fd, (const struct sockaddr *)&(server.client_addr),
	sizeof(server.client_addr));
  xlisten(server.fd, QUEUE);
  return (server);
}
