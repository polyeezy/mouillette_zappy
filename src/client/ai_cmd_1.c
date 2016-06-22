/*
** ai_cmd_1.c for ai cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:02:23 2016 Alexis Miele
** Last update Wed Jun 22 15:07:26 2016 Valerian Polizzi
*/

#include "client.h"

char	*send_and_get(t_ai *cli, char *cmd)
{
  send_cmd_server(client, cmd);
  get_server_response(&cli->socket);
  return (cli->last_response);
}

void	ai_avance(t_ai *client)
{
  send_and_get(client, "avance");
}

void	ai_droite(t_ai *client)
{
  send_cmd_server(client, "droite");
}

void	ai_gauche(t_ai *client)
{
  send_cmd_server(client, "gauche");
}

void	ai_voir(t_ai *client)
{
  send_cmd_server(client, "voir");
}

void	ai_inventaire(t_ai *client)
{
  send_cmd_server(client, "inventaire");
}
