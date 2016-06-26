/*
** init.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:30:16 2016 Loïc Weinhard
** Last update Sun Jun 26 11:24:13 2016 Alexis Miele
*/

#include <time.h>
#include "args.h"
#include "xfct.h"
#include "server.h"
#include "network.h"

static void		init_case(t_case *acase)
{
  int			i;

  acase->players = NULL;
  acase->materials.food = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.linemate = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.deraumere = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.sibur = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.mendiane = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.phiras = ((i = rand() % 8) > 3 ? 0 : i);
  acase->materials.thystame = ((i = rand() % 8) > 3 ? 0 : i);
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

static int		check_timeout(char **argv)
{
  return (g_server_args[5].used ? atoi(argv[get_arg(argv, "-t") + 1]) : 100);
}

t_server		init_server(char **argv)
{
  t_server		server;
  int			port;

  port = atoi(argv[get_arg(argv, "-p") + 1]);
  if ((server.timeout = check_timeout(argv)) <= 0)
    exit(dprintf(2, "Error! Time must be greater than 0.\n") * 0 - 1);
  server.teams = NULL;
  if (add_teams(&(server.teams), argv) == -1)
    exit(dprintf(2, "Error! The teams should not have the "
		 "same name or be called \"GRAPHIC\".\n") * 0 - 1);
  server.fd = xsocket(DOMAIN, TYPE, xgetprotobyname(PROTOCOL));
  server.fd_max = server.fd + 1;
  server.pile = NULL;
  server.graphic = NULL;
  server.client_addr.sin_family = DOMAIN;
  server.client_addr.sin_port = xhtons(server.fd, port);
  server.map = init_map(argv);
  server.width = atoi(argv[get_arg(argv, "-x") + 1]);
  server.height = atoi(argv[get_arg(argv, "-y") + 1]);
  server.client_addr.sin_addr.s_addr = ADDRESSES;
  server.client_size = sizeof(server.client_addr);
  xbind(server.fd, (const struct sockaddr *)&(server.client_addr),
	sizeof(server.client_addr));
  xlisten(server.fd, QUEUE);
  return (server);
}
