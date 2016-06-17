/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
<<<<<<< HEAD
** Last update Fri Jun 17 17:42:03 2016 Alexis Miele
=======
** Last update Fri Jun 17 15:07:05 2016 Loïc Weinhard
>>>>>>> 2e5ce198467ccfb1ba22a165f7f2674d4ed5bceb
*/

#include "args.h"
#include "utils.h"
#include "client.h"
#include "xfct.h"

char		*get_server_response(t_client_socket *cli, char **dest)
{
  char		buff[255];

  xread(cli->fd, &buff, 255);
  strcpy(*dest, buff);
  return (*dest);
}

int		send_cmd_server(t_client_socket *cli, char *msg)
{
  return (dprintf(cli->fd, "%s\n", msg));
}

void		join_game(t_client_socket *cli, char *team)
{
  char		*response;

  printf("%s", get_server_response(cli, &response));
  send_cmd_server(cli, team);
  printf("%s", get_server_response(cli, &response));
  printf("%s", get_server_response(cli, &response));
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
