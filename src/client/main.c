/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Mon Jun 13 10:45:33 2016 Loïc Weinhard
** Last update Fri Jun 17 15:02:47 2016 Loïc Weinhard
*/

#include "args.h"
#include "utils.h"
#include "client.h"
#include "xfct.h"

int		main(int argc, char **argv)
{
  t_client	client;

  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  client = init_client(argv);
  (void)client;
  xclose(client.fd);
  return (0);
}
