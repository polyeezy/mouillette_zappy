/*
** init.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 15:30:16 2016 Loïc Weinhard
** Last update Mon Jun 13 16:39:06 2016 Loïc Weinhard
*/

#include "args.h"
#include "xfct.h"
#include "server.h"
#include "network.h"

t_server		init_server(char **argv)
{
  t_server		server;
  int			port;

  port = atoi(argv[get_arg(argv, "-p") + 1]);
  server.fd = xsocket(DOMAIN, TYPE, xgetprotobyname(PROTOCOL));
  server.fd_max = server.fd + 1;
  server.timeout = atoi(argv[get_arg(argv, "-t") + 1]);
  server.teams = NULL;
  add_teams(&(server.teams), argv);
  server.client_addr.sin_family = DOMAIN;
  server.client_addr.sin_port = xhtons(server.fd, port);
  server.client_addr.sin_addr.s_addr = ADDRESSES;
  server.client_size = sizeof(server.client_addr);
  xbind(server.fd, (const struct sockaddr *)&(server.client_addr),
	sizeof(server.client_addr));
  xlisten(server.fd, QUEUE);
  return (server);
}
