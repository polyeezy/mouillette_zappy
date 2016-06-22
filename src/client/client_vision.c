/*
** client_vision.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 16:16:03 2016 Valerian Polizzi
** Last update Wed Jun 22 16:20:38 2016 Valerian Polizzi
*/

#include <client.h>
#include <utils.h>

char    **parse_voir(t_ai *cli)
{

  char          **parsing;

  printf("%s\n", send_and_get(cli, "voir"));
  parsing = my_str_to_wordtab(cli->last_response, "{,}");

  int          i = 0;

  while (parsing[i])
    {
      printf("%s\n", parsing[i++]);
    }
  return (parsing);
}
