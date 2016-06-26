/*
** main.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 10:45:12 2016 Loïc Weinhard
** Last update Sun Jun 26 21:29:33 2016 Aurelie Orset
*/

#include "args.h"
#include "utils.h"
#include "server.h"
#include "sig.h"
#include "xfct.h"
#include "cmds.h"
#include "graphic_client.h"

void		fd_zero_set_all(t_server *server)
{
  t_team	*team;
  t_client	*member;
  t_graphic	*graphics;

  FD_ZERO(&(server->readfds));
  FD_SET(server->fd, &(server->readfds));
  team = server->teams;
  while (team)
    {
      member = team->members;
      while (member)
	{
	  FD_SET(member->fd, &(server->readfds));
	  member = member->next;
	}
      team = team->next;
    }
  graphics = server->graphic;
  while (graphics)
    {
      FD_SET(graphics->fd, &(server->readfds));
      graphics = graphics->next;
    }
}

void		fd_isset_graphics(t_server *server)
{
  t_graphic	*graphics;
  t_graphic	*next;

  graphics = server->graphic;
  while (graphics)
    {
      next = graphics->next;
      if (FD_ISSET(graphics->fd, &(server->readfds)))
	handle_graphics(server, graphics);
      graphics = next;
    }
}

void		fd_isset_clients(t_server *server)
{
  t_team	*team;
  t_client	*member;
  t_client	*next;

  team = server->teams;
  while (team)
    {
      member = team->members;
      while (member)
	{
	  next = member->next;
	  if (FD_ISSET(member->fd, &(server->readfds)))
	    handle_cmds(server, member);
	  member = next;
	}
      team = team->next;
    }
  fd_isset_graphics(server);
}

static int	check_gameover(t_server server, char *msg, int end)
{
  t_team	*teams;
  t_client	*clients;

  teams = server.teams;
  while (teams)
    {
      clients = teams->members;
      while (clients)
	{
	  if (clients->level == 8 && msg == NULL && (end = 1))
	    check_gameover(server, "GAME OVER\n", 1);
	  else if (msg != NULL)
	    xwrite(clients->fd, msg);
	  clients = clients->next;
	}
      teams = teams->next;
    }
  return (end);
}

int			main(int argc, char **argv)
{
  t_server		server;
  int			ret;
  struct timeval	timinho;

  (void)argc;
  gettimeofday(&timinho, NULL);
  srand(timinho.tv_usec);
  if (check_args(argv) == -1)
    return (-1);
  server = init_server(argv);
  ret = 0;
  while (ret != -1 && check_gameover(server, NULL, 0) != 1)
    {
      fd_zero_set_all(&server);
      calc_delay(server.pile, &timinho);
      ret = select(server.fd_max, &(server.readfds), NULL, NULL,
		   (timinho.tv_sec >= 0 ? &timinho : NULL));
      exec_pile(&server, &(server.pile));
      if (FD_ISSET(server.fd, &(server.readfds)))
	accept_client(&server);
      fd_isset_clients(&server);
    }
  close_server(server);
  return (0);
}
