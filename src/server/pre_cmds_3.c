/*
** pre_cmds_3.c for pre cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 13:37:38 2016 Alexis Miele
** Last update Sun Jun 26 19:50:51 2016 Alexis Miele
*/

#include "cmds.h"
#include "xfct.h"
#include "pile.h"
#include "incantations.h"

static int      check_players(t_case pos, int level, int players, int fd)
{
  t_client      *tmp;
  int           i;

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

static void	tell_player(t_client **players)
{
  t_client	*tmp;

  tmp = *players;
  while (tmp)
    {
      xwrite(tmp->fd, "elevation en cours\n");
      tmp = tmp->next_map;
    }
}

void            pre_incantation(t_server *server, t_client *player,
				char *buffer, t_cmd *cmd)
{
  int           *case_material;
  int           *required_material;
  int           i;

  if (check_players(server->map[player->y][player->x], player->level,
                    g_levels[player->level - 1].players, player->fd) == -1)
    return;
  case_material = &(server->map[player->y][player->x].materials.linemate);
  required_material = &(g_levels[player->level - 1].materials.linemate);
  i = -1;
  while (++i < 6)
    {
      if (*case_material != *required_material)
        {
          xwrite(player->fd, "ko\n");
          return;
        }
      case_material++;
      required_material++;
    }
  tell_player(&(server->map[player->y][player->x].players));
  add_pile(server, player, strdup(buffer), cmd);
}
