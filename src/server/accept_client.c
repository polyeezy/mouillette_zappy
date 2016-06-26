/*
** client.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 17 14:04:48 2016 Loïc Weinhard
** Last update Sun Jun 26 21:36:51 2016 Aurelie Orset
*/

#include <time.h>
#include "team.h"
#include "server.h"
#include "xfct.h"

t_client	*create_client(t_server *server, int fd)
{
  t_client	*elem;

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
  return (elem);
}

static void	add_client(t_server *server, t_team **teams, char *team, int fd)
{
  t_team	*tmp_teams;

  tmp_teams = *teams;
  while (strncmp(tmp_teams->name, team, strlen(tmp_teams->name)) != 0)
    tmp_teams = tmp_teams->next;
  add_client_ext(&server, &(tmp_teams->members), fd);
}

static int	compare_teams(t_server server, char *team)
{
  int		players;
  t_team	*teams;
  t_client	*members;

  if (strncmp(team, "GRAPHIC", my_strlen("GRAPHIC")) == 0)
    return (-1);
  players = 0;
  teams = server.teams;
  while (teams)
    {
      if (strncmp(teams->name, team, my_strlen(teams->name)) == 0)
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

static void	add_mange(t_server **server, t_team **teams, char *team, int fd)
{
  t_client	*clients;
  t_team	*tmp_teams;

  tmp_teams = *teams;
  while (strncmp(tmp_teams->name, team, strlen(tmp_teams->name)) != 0)
    tmp_teams = tmp_teams->next;
  clients = tmp_teams->members;
  while (clients && clients->next && clients->fd != fd)
    clients = clients->next;
  pre_mange(*server, clients, "mange", &(g_cmds[NUMBER_OF_COMMANDS - 1]));
}

void		accept_client(t_server *server)
{
  int		new_fd;
  int		ret;
  char		buffer[4097];
  int		slots;

  new_fd = xaccept(server->fd,
                           (struct sockaddr *)&(server->client_addr),
                   &(server->client_size));
  dprintf(new_fd, "BIENVENUE\n");
  ret = xread(new_fd, buffer, 4096);
  buffer[ret] = 0;
  slots = compare_teams(*server, buffer);
  slots >= 0 ? dprintf(new_fd, "%d\n", slots) :
      add_graphic(server, &(server)->graphic, new_fd);
  if (slots > 0)
    {
      add_client(server, &(server->teams), buffer, new_fd);
      new_fd >= server->fd_max ? server->fd_max = new_fd + 1 : 0;
      dprintf(new_fd, "%d %d\n", server->width, server->height);
      add_mange(&server, &(server->teams), buffer, new_fd);
    }
  else if (slots == 0)
    xclose(new_fd);
  else
    new_fd >= server->fd_max ? server->fd_max = new_fd + 1 : 0;
}
