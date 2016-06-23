/*
** droite.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:29:22 2016 Loïc Weinhard
** Last update Thu Jun 23 14:32:31 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "cmds.h"

char	droite(t_server *server, t_client *player, char **tab)
{
  (void)server;
  (void)tab;
  player->orientation = (player->orientation + 1) % 4;
  xwrite(player->fd, "ok\n");
  return (0);
}
