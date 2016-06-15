/*
** client_check_params.c for  in /home/polyeezy/rendu/CPP/mouillette_zappy/src/client
** 
** Made by Valérian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Tue Jun 14 05:23:09 2016 Valérian Polizzi
** Last update Tue Jun 14 05:43:10 2016 Valérian Polizzi
*/

#include <client.h>

int		client_check_params(int ac, char **av)
{
  if (ac == 5)
    {
      if (strcmp(av[1], "-n") == 0 && strcmp(av[3], "-p") == 0)
	{
	  printf("host = local\n");
	  return (2);
	}
    }
  if (ac != 7)
    return (-1);
  if (strcmp(av[1], "-n") == 0 && strcmp(av[3], "-p") == 0 && strcmp(av[5], "-h") == 0)
    return (0);
  return (-2);
}
