/*
** remove_client.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Thu Jun 23 17:21:17 2016 Loïc Weinhard
** Last update Sun Jun 26 19:58:44 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "server.h"

static void	remove_from_pile(t_pile **pile, t_client *player)
{
  t_pile	*tmp;

  tmp = *pile;
  while (tmp)
    {
      if (tmp->player && tmp->player->fd == player->fd)
	tmp->player = NULL;
      tmp = tmp->next;
    }
}

static void	remove_from_map(t_client **client, t_client *player)
{
  t_client	*tmp;

  tmp = *client;
  while (tmp)
    {
      if (tmp->fd == player->fd)
	{
	  tmp->prev != NULL ? tmp->prev->next = tmp->next : 0;
	  tmp->next != NULL ? tmp->next->prev = tmp->prev : 0;
          if (tmp->prev == NULL && tmp->next == NULL)
	    *client = NULL;
	  return;
	}
      tmp = tmp->next;
    }
  return;
}

static void	remove_from_team(t_team **teams, t_client *player)
{
  t_client	*tmp;

  tmp = (*teams)->members;
  while (tmp)
    {
      if (tmp->fd == player->fd)
	{
	  if (tmp->prev != NULL)
	    tmp->prev->next = tmp->next;
	  if (tmp->next != NULL)
	    tmp->next->prev = tmp->prev;
	  if (tmp->prev == NULL && tmp->next == NULL)
	    (*teams)->members = NULL;
	  return;
	}
      tmp = tmp->next;
    }
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
	      remove_from_map(&(server->map[tmp->y][tmp->x].players), tmp);
	      remove_from_team(&(server->teams), tmp);
	      remove_from_pile(&(server->pile), tmp);
	      xclose(player->fd);
	      xfree(player);
	      return;
	    }
	  tmp = tmp->next;
	}
      teams = teams->next;
    }
}
