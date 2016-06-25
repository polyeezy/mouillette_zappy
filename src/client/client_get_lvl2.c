/*
** client_get_lvl2.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Sat Jun 25 13:01:52 2016 Valerian Polizzi
** Last update Sat Jun 25 15:36:38 2016 Valerian Polizzi
*/

#include <client.h>
// required : linemate 1 - deraumere 1 - sibur 1

void                    client_get_lvl2(t_ai *cli)
{
  char		**required;
   int		i;

   required = NULL;
  i = 0;

  // parsing = parse_voir(cli); ,,
  required = my_str_to_wordtab(" linemate deraumere sibur ", " ");

  while (required[i])
    {
      printf("GETTING -%s-\n", required[i]);
      go_get_object(cli, required[i++]);
    }
  i = 0;
  while (required[i])
    ai_pose(cli, required[i++]);
  get_rid(cli, required);
  // parsing = parse_voir(cli);
  ai_incantation(cli, " ");
}

