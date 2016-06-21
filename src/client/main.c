/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Tue Jun 21 17:35:44 2016 Valerian Polizzi
*/

#include "args.h"
#include "utils.h"
#include "client.h"
#include "xfct.h"


char		*get_server_response(t_client_socket *cli, char *msg)
{
  char		buff[254];
  ssize_t	len;

  xfree(msg);
  len = xread(cli->fd, &buff, 255);
  buff[len] = 0;
  msg = strdup(buff);
  return (msg);
}

t_materials	parse_inventaire(t_ai *cli)
{
  char		*msg;
  // char		**parsing;
  t_materials	inv;

  msg = NULL;
  send_cmd_server(&cli->socket, "inventaire");
  printf("%s\n", msg = get_server_response(&cli->socket, msg));
  (void)msg;
  return (inv);
}


int		send_cmd_server(t_client_socket *cli, char *msg)
{
  return (dprintf(cli->fd, "%s\n", msg));
}
void		game_loop(t_ai *cli)
{
  t_materials	inv;

  inv = parse_inventaire(cli);
  (void)inv;
}

void		join_game(t_ai *cli)
{
  char		*msg;

  msg = NULL;
  printf("%s", msg = get_server_response(&cli->socket, msg));
  send_cmd_server(&cli->socket, cli->team);
  printf("%s", msg = get_server_response(&cli->socket, msg));
  printf("%s", msg = get_server_response(&cli->socket, msg));
  game_loop(cli);
  xfree(msg);
}

void		init_ai(t_ai *ai, char **av)
{
  ai->lvl = 1;
  ai->last_response = NULL;
  ai->team = av[get_arg(av, "-n") + 1];
  ai->socket = init_client_socket(av);
  ai->state = LOOKING_FOR;
}

int		main(int argc, char **argv)
{
  t_ai		ai;
//t_client_socket	client;

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  init_ai(&ai, argv);
  join_game(&ai);
  xclose(ai.socket.fd);
  return (0);
}

