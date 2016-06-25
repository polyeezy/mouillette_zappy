/*
** ai_cmd_2.c for ai cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:22:38 2016 Alexis Miele
** Last update Sat Jun 25 15:30:06 2016 Valerian Polizzi
*/

#include "client.h"
#include "xfct.h"

void	ai_prend(t_ai *client, char *arg)
{
  char	*msg;

  msg = xcalloc(6 + strlen(arg) + 1, sizeof(char));
  strcat(msg, "prend ");
  strcat(msg, arg);
  send_and_get(client, msg);
  xfree(msg);
}

void	ai_pose(t_ai *client, char *arg)
{
  char	*msg;

  msg = xcalloc(5 + strlen(arg) + 1, sizeof(char));
  strcat(msg, "pose ");
  strcat(msg, arg);
  send_cmd_server(client, msg);
  xfree(msg);
}

void	ai_expulse(t_ai *client, char *arg)
{
  (void)arg;
  send_cmd_server(client, "expulse");
}

void	ai_broadcast(t_ai *client, char *arg)
{
  char	*msg;

  msg = xcalloc(10 + strlen(arg) + 1, sizeof(char));
  strcat(msg, "broadcast ");
  strcat(msg, arg);
  send_cmd_server(client, msg);
  xfree(msg);
}

void	ai_incantation(t_ai *client, char *arg)
{
  (void)arg;  
  send_and_get(client, "incantation");
}
