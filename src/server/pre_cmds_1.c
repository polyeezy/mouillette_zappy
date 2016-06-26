/*
** pre_cmds.c for pre cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 13:17:21 2016 Alexis Miele
** Last update Sun Jun 26 14:53:34 2016 Alexis Miele
*/

#include "cmds.h"
#include "pile.h"

void	pre_avance(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_droite(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_gauche(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_voir(t_server *server, t_client *player, char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_inventaire(t_server *server, t_client *player,
		       char *buffer, t_cmd *cmd)
{
  add_pile(server, player, strdup(buffer), cmd);
}
