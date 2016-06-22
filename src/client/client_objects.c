/*
** client_objects.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 16:00:20 2016 Valerian Polizzi
** Last update Wed Jun 22 16:24:11 2016 Valerian Polizzi
*/

#include <client.h>
#include <utils.h>
#include <stdlib.h>
#include <args.h>

int             object_is_in_cell(char *cell, char *obj)
{
  char          **content;
  int           i;

  content = NULL;
  i = 0;
  content = my_str_to_wordtab(cell, " ");
  while (content[i])
    {

      if (strncmp(content[i], obj, strlen(obj)) == 0)
        return (1);
      i++;
    }
  return (-1);
}

int             look_for_object(char **vision, char *to_find)
{
  int           i;
  int                  res;

  i = 0;
  res = 0;
  while (vision[i])
    {
      res = object_is_in_cell(vision[i], to_find);
      if (res > 0)
        return (i);
      i++;
    }
  return (-1);
}

t_materials  parse_inventaire(t_ai *cli)
{
  char               *msg;
  char               **parsing;
  t_materials        inv;

  msg = NULL;
  printf("%s\n", send_and_get(cli, "inventaire"));
   parsing = my_str_to_wordtab(msg, "{ , }");
  inv.food = atoi(parsing[get_arg(parsing, "nourriture") + 1]);
  inv.linemate = atoi(parsing[get_arg(parsing, "linemate") + 1]);
  inv.deraumere = atoi(parsing[get_arg(parsing, "deraumere") + 1]);
  inv.sibur = atoi(parsing[get_arg(parsing, "sibur") + 1]);
  inv.mendiane = atoi(parsing[get_arg(parsing, "mendiane") + 1]);
  inv.phiras = atoi(parsing[get_arg(parsing, "phiras") + 1]);
  inv.thystame = atoi(parsing[get_arg(parsing, "thystame") + 1]);
  debug_material(&inv);
  return (inv);
}

