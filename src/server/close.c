/*
** close.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:11:05 2016 Loïc Weinhard
** Last update Mon Jun 13 16:40:43 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "server.h"

void	close_server(t_server server)
{
  xclose(server.fd);
  free_teams(server.teams);
}
