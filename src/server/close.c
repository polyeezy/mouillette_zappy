/*
** close.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:11:05 2016 Loïc Weinhard
** Last update Tue Jun 14 16:50:48 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "server.h"

void	free_map(t_case **map)
{
  int	i;

  i = 0;
  while (map[i])
    xfree(map[i++]);
  xfree(map);
}

void	close_server(t_server server)
{
  xclose(server.fd);
  free_teams(server.teams);
  free_map(server.map);
}
