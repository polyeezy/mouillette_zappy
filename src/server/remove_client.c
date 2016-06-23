/*
** remove_client.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Thu Jun 23 17:21:17 2016 Loïc Weinhard
** Last update Thu Jun 23 18:13:19 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "server.h"

static t_case	**remove_from_map(t_case **map, t_client *player)
{
  t_client	*tmp;

  tmp = map[player->y][player->x].players;
  while (tmp)
    {
      if (tmp->fd == player->fd)
	{
	  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
	  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
          tmp->prev == NULL && tmp->next == NULL ? tmp = NULL : 0;
	  while (tmp && tmp->prev)
	    tmp = tmp->prev;
	  map[player->y][player->x].players = tmp;
	  return (map);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

static t_team	*remove_from_team(t_team *teams, t_client *player)
{
  t_client	*tmp;

  tmp = teams->members;
  while (tmp)
    {
      if (tmp->fd == player->fd)
	{
	  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
	  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
	  tmp->prev == NULL && tmp->next == NULL ? tmp = NULL : 0;
	  while (tmp && tmp->prev)
	    tmp = tmp->prev;
	  teams->members = tmp;
	  while (teams->prev)
	    teams = teams->prev;
	  return (teams);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		remove_client(t_server *server, t_client *player, int ret)
{
  t_team	*teams;
  t_client	*tmp;

  if (ret != 0)
    return;
  teams = server->teams;
  while (teams)
    {
      tmp = teams->members;
      while (tmp)
	{
	  if (tmp->fd == player->fd)
	    {
	      server->map = remove_from_map(server->map, tmp);
	      server->teams = remove_from_team(server->teams, tmp);
	      xclose(player->fd);
	      xfree(player);
	      return;
	    }
	  tmp = tmp->next;
	}
      teams = teams->next;
    }
}
