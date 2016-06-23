/*
** gauche.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:42:59 2016 Loïc Weinhard
** Last update Thu Jun 23 14:32:44 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "cmds.h"

char	gauche(t_server *server, t_client *player, char **tab)
{
  (void)server;
  (void)tab;
  if (player->orientation == 0)
    player->orientation = 3;
  else
    player->orientation -= 1;
  xwrite(player->fd, "ok\n");
  return (0);
}
