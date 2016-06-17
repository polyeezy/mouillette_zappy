/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Fri Jun 17 08:01:02 2016 Valérian Polizzi
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

int		send_cmd_server(t_client_socket *cli, char *msg)
{
  return (dprintf(cli->fd, "%s\n", msg));
}

void		join_game(t_client_socket *cli, char *team)
{
  char		*msg;
 
  msg = NULL;
  printf("%s", msg = get_server_response(cli, msg));
  send_cmd_server(cli, team);
  printf("%s", msg = get_server_response(cli, msg));
  printf("%s", msg = get_server_response(cli, msg));
  xfree(msg);
}

int		main(int argc, char **argv)
{
  t_client_socket	client;

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  client = init_client_socket(argv);
  join_game(&client, argv[get_arg(argv, "-n") + 1]);
  xclose(client.fd);

  return (0);
}
