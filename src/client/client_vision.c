/*
** client_vision.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Wed Jun 22 16:16:03 2016 Valerian Polizzi
** Last update Sun Jun 26 11:34:30 2016 Valerian Polizzi
*/

#include <client.h>
#include <utils.h>

char	**parse_voir(t_ai *cli)
{
  char	**parsing;

  send_and_get(cli, "voir");
  parsing = my_str_to_wordtab(cli->last_response, "{,}");
  return (parsing);
}
