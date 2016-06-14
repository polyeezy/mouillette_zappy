/*
** main.c for main in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Tue Jun 14 17:27:58 2016 Alexis Miele
** Last update Tue Jun 14 17:28:37 2016 Alexis Miele
*/

#include "args.h"
#include "utils.h"
#include "client.h"

int		main(int argc, char **argv)
{
  (void)argc;
  if (check_args(argv) == -1)
    return (-1);
  return (0);
}
