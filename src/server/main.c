/*
** main.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 10:45:12 2016 Loïc Weinhard
** Last update Fri Jun 17 12:19:28 2016 Loïc Weinhard
*/

#include "args.h"
#include "utils.h"
#include "server.h"
#include "sig.h"
#include "xfct.h"

extern char g_exit;

void		fd_zero_set_all(t_server *server)
{
  t_team	*team;
  t_client	*member;

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
}

void		fd_isset_clients(t_server *server)
{
  t_team	*team;
  t_client	*member;

  team = server->teams;
  while (team)
    {
      member = team->members;
      while (member)
	{
	  if (FD_ISSET(member->fd, &(server->readfds)))
	    dprintf(1, "Le client %d de la team %s a fait un truc.\n",
		    member->fd, member->team);
	  member = member->next;
	}
      team = team->next;
    }
}

int		main(int argc, char **argv)
{
  t_server	server;
  int		ret;
  int		new_fd;

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  server = init_server(argv);
  ret = 0;
  g_exit = 0;
  while (ret != -1 && g_exit != 1)
    {
      fd_zero_set_all(&server);
      ret = select(server.fd_max, &(server.readfds), NULL, NULL, NULL);
      if (FD_ISSET(server.fd, &(server.readfds)))
	{
	  new_fd = xaccept(server.fd,
      			   (struct sockaddr *)&(server.client_addr),
			   &(server.client_size));
	  new_fd > server.fd_max ? server.fd_max = new_fd + 1 : 0;
	}
      fd_isset_clients(&server);
    }
  close_server(server);
  return (0);
}
