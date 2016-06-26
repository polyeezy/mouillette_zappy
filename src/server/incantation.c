/*
** incantation.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 15:30:55 2016 Loïc Weinhard
** Last update Sun Jun 26 19:50:26 2016 Alexis Miele
*/

#include "xfct.h"
#include "server.h"
#include "incantations.h"

static int	check_players(t_case pos, int level, int players, int fd)
{
  t_client	*tmp;
  int		i;

  tmp = pos.players;
  i = 0;
  while (tmp)
    {
      if (tmp->level == level)
	i += 1;
      else
	{
	  xwrite(fd, "ko\n");
	  return (-1);
	}
      tmp = tmp->next_map;
    }
  if (i != players)
    {
      xwrite(fd, "ko\n");
      return (-1);
    }
  else
    return (0);
}

static void	level_up(t_client **players)
{
  t_client	*tmp;

  tmp = *players;
  while (tmp)
    {
      tmp->level += 1;
      dprintf(tmp->fd, "niveau actuel : %d\n", tmp->level);
      tmp = tmp->next_map;
    }
}

char		incantation(t_server *server, t_client *player, char **tab)
{
  int		*case_material;
  int		*required_material;
  int		i;

  (void)tab;
  if (check_players(server->map[player->y][player->x], player->level,
		    g_levels[player->level - 1].players, player->fd) == -1)
    return (0);
  case_material = &(server->map[player->y][player->x].materials.linemate);
  required_material = &(g_levels[player->level - 1].materials.linemate);
  i = -1;
  while (++i < 6)
    {
      if (*case_material != *required_material)
	{
	  xwrite(player->fd, "ko\n");
	  return (0);
	}
      case_material++;
      required_material++;
    }
  level_up(&player);
  return (0);
}
