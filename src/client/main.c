/*
** main.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/client/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Tue Jun 14 06:32:07 2016 Valérian Polizzi
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
