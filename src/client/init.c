/*
** init.c for init in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Wed Jun 15 14:18:53 2016 Alexis Miele
** Last update Fri Jun 17 15:02:58 2016 Loïc Weinhard
*/

#include "args.h"
#include "xfct.h"
#include "client.h"
#include "network.h"

t_client		init_client(char **argv)
{
  t_client		client;
  int			port;

  port = atoi(argv[get_arg(argv, "-p") + 1]);
  client.fd = socket(DOMAIN, TYPE, xgetprotobyname(PROTOCOL));
  client.server_addr.sin_family = DOMAIN;
  client.server_addr.sin_port = xhtons(client.fd, port);
  if (g_client_args[2].used)
    client.server_addr.sin_addr.s_addr =
      inet_addr(argv[get_arg(argv, "-h") + 1]);
  else
    client.server_addr.sin_addr.s_addr = inet_addr("localhost");
  client.server_size = sizeof(client.server_addr);
  xconnect(client.fd, (struct sockaddr *)&(client.server_addr),
	   sizeof(client.server_addr));
  return (client);
}
