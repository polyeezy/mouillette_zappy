/*
** avance.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 11:21:52 2016 Loïc Weinhard
** Last update Sun Jun 26 19:23:05 2016 Alexis Miele
*/

#include "utils.h"
#include "cmds.h"
#include "xfct.h"

static char	nord(t_server **server, t_client **members, t_client **player)
{
  if ((*player)->prev_map != NULL)
    (*player)->prev_map->next_map = (*player)->next_map;
  if ((*player)->next_map != NULL)
    (*player)->next_map->prev_map = (*player)->prev_map;
  if ((*player)->prev_map == NULL && (*player)->next_map == NULL)
    *members = NULL;
  (*player)->y = mod((*player)->y - 1, (*server)->height);
  add_player_on_map(&((*server)->map[(*player)->y][(*player)->x].players),
		    player);
  return (0);
}

static char	est(t_server **server, t_client **members, t_client **player)
{
  if ((*player)->prev_map != NULL)
    (*player)->prev->next_map = (*player)->next_map;
  if ((*player)->next_map != NULL)
    (*player)->next_map->prev_map = (*player)->prev_map;
  if ((*player)->prev_map == NULL && (*player)->next_map == NULL)
    *members = NULL;
  (*player)->x = mod((*player)->x + 1, (*server)->height);
  add_player_on_map(&((*server)->map[(*player)->y][(*player)->x].players),
		    player);
  return (0);
}

static char	sud(t_server **server, t_client **members, t_client **player)
{
  if ((*player)->prev_map != NULL)
    (*player)->prev_map->next_map = (*player)->next_map;
  if ((*player)->next_map != NULL)
    (*player)->next_map->prev_map = (*player)->prev_map;
  if ((*player)->prev_map == NULL && (*player)->next_map == NULL)
    *members = NULL;
  (*player)->y = mod((*player)->y + 1, (*server)->height);
  add_player_on_map(&((*server)->map[(*player)->y][(*player)->x].players),
		    player);
  return (0);
}

static char	ouest(t_server **server, t_client **members, t_client **player)
{
  if ((*player)->prev_map != NULL)
    (*player)->prev_map->next_map = (*player)->next_map;
  if ((*player)->next_map != NULL)
    (*player)->next_map->prev_map = (*player)->prev_map;
  if ((*player)->prev_map == NULL && (*player)->next_map == NULL)
    *members = NULL;
  (*player)->x = mod((*player)->x - 1, (*server)->height);
  add_player_on_map(&((*server)->map[(*player)->y][(*player)->x].players),
		    player);
  return (0);
}

char		avance(t_server *server, t_client *player, char **tab)
{
  char		(*ptr_func[4])(t_server **server, t_client **members,
			       t_client **player);

  (void)tab;
  ptr_func[NORTH] = &nord;
  ptr_func[EAST] = &est;
  ptr_func[SOUTH] = &sud;
  ptr_func[WEST] = &ouest;
  ptr_func[player->orientation](&server,
				&(server->map[player->y][player->x].players), &player);
  xwrite(player->fd, "ok\n");
  return (0);
}
