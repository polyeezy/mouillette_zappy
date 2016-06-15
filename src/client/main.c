/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Wed Jun 15 02:39:10 2016 Valérian Polizzi
*/

#include <client.h>

int	main(int ac, char **av)
{
  t_client	*cli;
  int		init;

  if ((init = client_check_params(ac, av)) == 0)
    client_init(&cli, av[2], av[4], av[6]);
  else if (init == 2)
    client_init(&cli, av[2], av[4], "localhost");
  else
    return (printf("ko\n"));
  return (0);
}
/* #include "args.h" */
/* #include "utils.h" */
/* #include "client.h" */

/* int		main(int argc, char **argv) */
/* { */
/*   (void)argc; */
/*   if (check_args(argv) == -1) */
/*     return (-1); */
/*   return (0); */
/* } */
