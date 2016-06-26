/*
** connect_nbr.c for connect_nbr in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 14:43:25 2016 Alexis Miele
** Last update Sun Jun 26 14:58:16 2016 Alexis Miele
*/

#include "cmds.h"
#include "xfct.h"

char	connect_nbr(t_server *server, t_client *player, char **tab)
{
  (void)server;
  (void)tab;
  xwrite(player->fd, "ko\n");
  return (0);
}
