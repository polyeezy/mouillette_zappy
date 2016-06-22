/*
** avance.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 11:21:52 2016 Loïc Weinhard
** Last update Wed Jun 22 16:37:17 2016 Loïc Weinhard
*/

#include "utils.h"
#include "cmds.h"
#include "xfct.h"

static char	nord(t_server *server, t_client *player)
{
  t_client	*tmp;

  tmp = server->map[player->y][player->x].players;
  while (tmp->fd != player->fd && (tmp = tmp->next));
  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  player->y = mod(player->y - 1, server->height);
  tmp = server->map[player->y][player->x].players;
  while (tmp)
    tmp = tmp->next;
  tmp = relink(tmp, player);
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  return (0);
}

static char	est(t_server *server, t_client *player)
{
  t_client	*tmp;

  tmp = server->map[player->y][player->x].players;
  while (tmp->fd != player->fd && (tmp = tmp->next));
  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  player->x = mod(player->x + 1, server->height);
  tmp = server->map[player->y][player->x].players;
  while (tmp)
    tmp = tmp->next;
  tmp = relink(tmp, player);
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  return (0);
}

static char	sud(t_server *server, t_client *player)
{
  t_client	*tmp;

  tmp = server->map[player->y][player->x].players;
  while (tmp->fd != player->fd && (tmp = tmp->next));
  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  player->y = mod(player->y + 1, server->height);
  tmp = server->map[player->y][player->x].players;
  while (tmp)
    tmp = tmp->next;
  tmp = relink(tmp, player);
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  return (0);
}

static char	ouest(t_server *server, t_client *player)
{
  t_client	*tmp;

  tmp = server->map[player->y][player->x].players;
  while (tmp->fd != player->fd && (tmp = tmp->next));
  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  player->x = mod(player->x - 1, server->height);
  tmp = server->map[player->y][player->x].players;
  while (tmp)
    tmp = tmp->next;
  tmp = relink(tmp, player);
  while (tmp->prev && (tmp = tmp->prev));
  server->map[player->y][player->x].players = tmp;
  return (0);
}

char	avance(t_server *server, t_client *player, char **tab)
{
  char	(*ptr_func[4])(t_server *server, t_client *player);

  (void)tab;
  ptr_func[NORTH] = &nord;
  ptr_func[EAST] = &est;
  ptr_func[SOUTH] = &sud;
  ptr_func[WEST] = &ouest;
  ptr_func[player->orientation](server, player);
  dprintf(player->fd, "ok\n");
  return (0);
}
