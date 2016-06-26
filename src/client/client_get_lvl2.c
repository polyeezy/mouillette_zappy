/*
** client_get_lvl2.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Sat Jun 25 13:01:52 2016 Valerian Polizzi
** Last update Sun Jun 26 17:23:31 2016 Loïc Weinhard
*/

#include <client.h>
// required : linemate 1 - deraumere 1 - sibur 1

void		client_get_lvl2(t_ai *cli)
{
  char		**required;
  int		i;

  required = NULL;
  i = 0;
  required = my_str_to_wordtab("linemate deraumere sibur", " ");
  while (required[i])
    {
      printf("LOOKIN LOOKIN %s\n", required[i]);
      go_get_object(cli, required[i++]);
    }
  i = 0;
   while (required[i])
    {
      ai_pose(cli, required[i++]);
     }
  get_rid(cli, required);
  ai_incantation(cli, " ");
}
