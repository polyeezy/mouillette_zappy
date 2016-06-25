/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Sat Jun 25 10:45:46 2016 Valerian Polizzi
*/

#include "args.h"
#include "client.h"
#include "xfct.h"
 
void		game_loop(t_ai *cli)
{
  client_get_lvl1(cli);
  while (strcmp(cli->last_response, "mort\n") != 0)
    {
      client_get_food(cli);
    }
}

void		join_game(t_ai *cli)
{
  printf("%s", get_server_response(cli));
  printf("%s", send_and_get(cli, cli->team));
  printf("%s", get_server_response(cli));
  game_loop(cli);
  xfree(cli->last_response);
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

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  init_ai(&ai, argv);
  join_game(&ai);
  xclose(ai.socket.fd);
  return (0);
}
