/*
** pre_cmds_2.c for pre cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 13:28:48 2016 Alexis Miele
** Last update Sun Jun 26 15:42:56 2016 Alexis Miele
*/

#include "cmds.h"
#include "pile.h"

void    pre_prend(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void    pre_pose(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void    pre_broadcast(t_server *server, t_client *player,
		      char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void    pre_mange(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void    pre_connect_nbr(t_server *server, t_client *player,
			char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}
