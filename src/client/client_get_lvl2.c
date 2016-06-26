/*
** client_get_lvl2.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Sat Jun 25 13:01:52 2016 Valerian Polizzi
** Last update Sun Jun 26 20:13:10 2016 Valerian Polizzi
*/

#include <client.h>

void		client_get_lvl2(t_ai *cli)
{
  char		**required;
  int		i;

  required = NULL;
  i = 0;
  required = my_str_to_wordtab("linemate deraumere sibur", " ");
  while (required[i])
    go_get_object(cli, required[i++]);
  i = 0;
  deblaye(cli);
  while (required[i])
    ai_pose(cli, required[i++]);
  free_tab(required);
  ai_broadcast(cli, "INCANTATION 2-3");
  ai_incantation(cli);
}
