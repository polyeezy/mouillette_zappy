/*
** gauche.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:42:59 2016 Loïc Weinhard
** Last update Sat Jun 18 16:46:15 2016 Loïc Weinhard
*/

#include "cmds.h"

char	gauche(t_server *server, t_client *player, char **tab)
{
  (void)server;
  (void)tab;
  player->orientation -= 1;
  if (player->orientation < 0)
    player->orientation = 3;
  return (0);
}
