/*
** init.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:30:16 2016 Loïc Weinhard
** Last update Tue Jun 14 16:43:06 2016 Loïc Weinhard
*/

#include "args.h"
#include "xfct.h"
#include "server.h"
#include "network.h"

static t_case		**init_map(char **argv)
{
  t_case		**map;
  int			i;
  int			x;

  map = xmalloc((atoi(argv[get_arg(argv, "-y") + 1]) + 1) * sizeof(t_case *));
  i = 0;
  while (i < atoi(argv[get_arg(argv, "-y")]))
    {
      map[i] = xmalloc((atoi(argv[get_arg(argv, "-h")])));
      x = 0;
      while (x < atoi(argv[get_arg(argv, "-h")]))
	{
	  map[i][x].materials.food = 0;
	  map[i][x].materials.linemate = 0;
	  map[i][x].materials.deraumere = 0;
	  map[i][x].materials.sibur = 0;
	  map[i][x].materials.mendiane = 0;
	  map[i][x].materials.phiras = 0;
	  map[i][x].materials.thystame = 0;
	  x += 1;
	}
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
  add_teams(&(server.teams), argv);
  server.client_addr.sin_addr.s_addr = ADDRESSES;
  server.client_size = sizeof(server.client_addr);
  xbind(server.fd, (const struct sockaddr *)&(server.client_addr),
	sizeof(server.client_addr));
  xlisten(server.fd, QUEUE);
  return (server);
}
