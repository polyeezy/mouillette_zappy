/*
** ai_cmd_3.c for ai cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:30:41 2016 Alexis Miele
** Last update Fri Jun 17 17:40:32 2016 Alexis Miele
*/

#include "client.h"
#include "xfct.h"

void	ai_fork(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "fork");
}

void	ai_connect_nbr(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "connect_nbr");
}

void	ai_dead(t_client_socket *client, char *arg)
{
  (void)arg;
  xclose(client->fd);
}
