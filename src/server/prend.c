/*
** prend.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 14:11:07 2016 Loïc Weinhard
** Last update Wed Jun 22 14:43:25 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "utils.h"
#include "cmds.h"

char	prend(t_server *server, t_client *player, char **tab)
{
  int	*material;
  int	*player_material;
  int	i;
  int	x;

  if ((i = check_syntax(player, tab)) == -1)
    return (1);
  material = &(server->map[player->y][player->x].materials.food);
  x = -1;
  while (i - ++x > 0)
    material++;
  if (*material == 0)
    {
      dprintf(player->fd, "ko\n");
      return (0);
    }
  player_material = &(player->materials.food);
  x = -1;
  while (i - ++x > 0)
    player_material++;
  *material -= 1;
  *player_material += 1;
  dprintf(player->fd, "ok\n");
  return (0);
}
