/*
** client.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 17 14:04:48 2016 Loïc Weinhard
** Last update Fri Jun 17 16:35:57 2016 Loïc Weinhard
*/

#include <time.h>
#include "team.h"
#include "server.h"
#include "xfct.h"

static t_client	*create_client(t_server server, int fd)
{
  t_client	*elem;

  srand(time(NULL));
  elem = xmalloc(sizeof(t_client));
  elem->fd = fd;
  elem->x = rand() % (server.width + 1);
  elem->y = rand() % (server.height + 1);
  elem->orientation = rand() % 5;
  elem->materials.food = 10;
  elem->materials.linemate = 0;
  elem->materials.deraumere = 0;
  elem->materials.sibur = 0;
  elem->materials.mendiane = 0;
  elem->materials.phiras = 0;
  elem->materials.thystame = 0;
  elem->next = NULL;
  return (elem);
}

static void	add_client(t_server server, t_team **teams, char *team, int fd)
{
  t_team	*tmp;
  t_client	*tmp_client;

  tmp = *(teams);
  while (tmp)
    {
      if (strcmp(tmp->name, team) == 0)
	{
	  tmp_client = tmp->members;
	  while (tmp_client && tmp_client->next)
	    tmp_client = tmp_client->next;
	  if (tmp_client == NULL)
	    {
	      tmp_client = create_client(server, fd);
	      tmp_client->prev = NULL;
	    }
	  else
	    {
	      tmp_client->next = create_client(server, fd);
	      tmp_client->prev = tmp_client;
	    }
	  return;
	}
      tmp = tmp->next;
    }
}

static int	compare_teams(t_server server, char *team)
{
  int		players;

  players = 0;
  while (server.teams)
    {
      if (strncmp(server.teams->name, team, strlen(server.teams->name)) == 0)
	{
	  while (server.teams->members)
	    {
	      server.teams->members = server.teams->members->next;
	      players += 1;
	    }
	  return (server.teams->max - players);
	}
      server.teams = server.teams->next;
    }
  return (0);
}

void	accept_client(t_server *server)
{
  int	new_fd;
  int	ret;
  char	buffer[4097];

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
      new_fd > server->fd_max ? server->fd_max = new_fd + 1 : 0;
      dprintf(new_fd, "%d %d\n", server->width, server->height);
    }
}
