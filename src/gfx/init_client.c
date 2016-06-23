/*
** init.c for init in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Wed Jun 15 14:18:53 2016 Alexis Miele
** Last update Thu Jun 23 18:43:14 2016 Aurelie Orset
*/

#include "args.h"
#include "xfct.h"
#include "client.h"
#include "network.h"
#include "graphic.h"

t_client_socket		init_client_socket(char **argv)
{
  t_client_socket      	client;
  int			port;

  port = atoi(argv[get_arg(argv, "-p") + 1]);
  client.fd = xsocket(AF_INET, SOCK_STREAM, xgetprotobyname("TCP"));
  client.server_addr.sin_family = AF_INET;
  client.server_addr.sin_port = xhtons(client.fd, port);
  if (g_gfx_args[2].used)
    client.server_addr.sin_addr.s_addr =
      inet_addr(argv[get_arg(argv, "-h") + 1]);
  else
    client.server_addr.sin_addr.s_addr = inet_addr("0");
  xconnect(client.fd, (struct sockaddr *)&(client.server_addr),
	   sizeof(client.server_addr));
  return (client);
}
