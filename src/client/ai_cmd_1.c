/*
** ai_cmd_1.c for ai cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:02:23 2016 Alexis Miele
** Last update Fri Jun 17 17:22:13 2016 Alexis Miele
*/

#include "client.h"

void	ai_avance(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "avance");
}

void	ai_droite(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "droite");
}

void	ai_gauche(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "gauche");
}

void	ai_voir(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "voir");
}

void	ai_inventaire(t_client_socket *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "inventaire");
}
