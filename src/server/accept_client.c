/*
** client.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 17 14:04:48 2016 Loïc Weinhard
** Last update Wed Jun 22 15:51:19 2016 Loïc Weinhard
*/

#include <time.h>
#include "team.h"
#include "server.h"
#include "xfct.h"

static t_client	*create_client(t_server *server, int fd)
{
  t_client	*elem;
  t_client	*tmp;

  elem = xmalloc(sizeof(t_client));
  elem->fd = fd;
  elem->level = 1;
  elem->x = rand() % server->width;
  elem->y = rand() % server->height;
  elem->orientation = rand() % 4;
  elem->materials.food = 10;
  elem->materials.linemate = 0;
  elem->materials.deraumere = 0;
  elem->materials.sibur = 0;
  elem->materials.mendiane = 0;
  elem->materials.phiras = 0;
  elem->materials.thystame = 0;
  elem->next = NULL;
  tmp = server->map[elem->y][elem->x].players;
  while (tmp && tmp->next && (tmp = tmp->next));
  elem->prev = (tmp != NULL ? tmp : NULL);
  tmp = (tmp != NULL ? tmp : elem);
  tmp->next = (tmp != elem ? elem : NULL);
  while (tmp->prev && (tmp = tmp->prev));
  server->map[elem->y][elem->x].players = tmp;
  return (elem);
}

static void	add_client(t_server server, t_team **teams, char *team, int fd)
{
  t_client	*clients;
  t_team	*tmp_teams;

  tmp_teams = *teams;
  while (strncmp(tmp_teams->name, team, strlen(tmp_teams->name)) != 0)
    tmp_teams = tmp_teams->next;
  clients = tmp_teams->members;
  while (clients && clients->next)
    clients = clients->next;
  if (clients == NULL)
    {
      clients = create_client(&server, fd);
      clients->prev = NULL;
    }
  else
    {
      clients->next = create_client(&server, fd);
      clients->next->prev = clients;
    }
  while (clients->prev)
    clients = clients->prev;
  tmp_teams->members = clients;
}

static int	compare_teams(t_server server, char *team)
{
  int		players;
  t_team	*teams;
  t_client	*members;

  players = 0;
  teams = server.teams;
  while (teams)
    {
      if (strncmp(teams->name, team, strlen(teams->name)) == 0)
	{
	  members = teams->members;
	  while (members)
	    {
	      members = members->next;
	      players += 1;
	    }
	  return (teams->max - players);
	}
      teams = teams->next;
    }
  return (0);
}

void		accept_client(t_server *server)
{
  int		new_fd;
  int		ret;
  char		buffer[4097];

  new_fd = xaccept(server->fd,
                           (struct sockaddr *)&(server->client_addr),
                   &(server->client_size));
  dprintf(new_fd, "BIENVENUE\n");
  ret = xread(new_fd, buffer, 4096);
  buffer[ret] = 0;
  dprintf(new_fd, "%d\n", compare_teams(*server, buffer));
  if (compare_teams(*server, buffer) != 0)
    {
      add_client(*server, &(server->teams), buffer, new_fd);
      new_fd >= server->fd_max ? server->fd_max = new_fd + 1 : 0;
      dprintf(new_fd, "%d %d\n", server->width, server->height);
    }
}
