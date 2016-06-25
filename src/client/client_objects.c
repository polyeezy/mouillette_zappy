/*
** client_objects.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 16:00:20 2016 Valerian Polizzi
** Last update Sat Jun 25 11:30:01 2016 Valerian Polizzi
*/

#include <client.h>
#include <utils.h>
#include <stdlib.h>
#include <args.h>
#include "xfct.h"

char		*epur_str(char *str)
{
  char *src;
  int i;
  int j;
  i = 0;
  j = 0;
  src = xmalloc(sizeof(char *) * strlen(str));
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i = i + 1;
	  if (j > 0 && str[i] != '\0')
	    src[j++] = ' ';
	}
      src[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  src[j] = '\0';
  return (src);
}

int             object_is_in_cell(char *cell, char *obj)
{
  char          **content;
  int           i;

  content = NULL;
  i = 0;
  content = my_str_to_wordtab(cell, " ");
  while (content[i])
    {

      if (strncmp(epur_str(content[i]), obj, strlen(obj)) == 0)
        return (1);
      i++;
    }
  return (-1);
}

void		get_rid(t_ai *cli, char **required)
{
  char		**content;
  char		*cell;
  char		**floor;
  

  int		i;
  int		j;

  content = parse_voir(cli);
  cell = content[0];
  floor = my_str_to_wordtab(cell, " ");
  while (floor[i])
    {
      j = 0;
      while (required[j])
	{
	  if (strcmp(required[j], epur_str(floor[i])) != 0 && strcmp(epur_str(floor[i]), "joueur") != 0)
	    ai_prend(cli, floor[i]);
	  j++;
	}
      i++;
    }
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
      if (res >= 0)
	{
	  printf("--%s FOUND %d--\n", to_find, i);
	  return (i);
	} 
     i++;
    }
  return (-1);
}

t_materials  parse_inventaire(t_ai *cli)
{
  //  char               **parsing;
   t_materials        inv;

   inv.food = 10;
  printf("%s\n", send_and_get(cli, "inventaire"));
  /* parsing = my_str_to_wordtab(msg, "{ , }"); */
  /* inv.food = atoi(parsing[get_arg(parsing, "nourriture") + 1]); */
  /* inv.linemate = atoi(parsing[get_arg(parsing, "linemate") + 1]); */
  /* inv.deraumere = atoi(parsing[get_arg(parsing, "deraumere") + 1]); */
  /* inv.sibur = atoi(parsing[get_arg(parsing, "sibur") + 1]); */
  /* inv.mendiane = atoi(parsing[get_arg(parsing, "mendiane") + 1]); */
  /* inv.phiras = atoi(parsing[get_arg(parsing, "phiras") + 1]); */
  /* inv.thystame = atoi(parsing[get_arg(parsing, "thystame") + 1]); */
  /* debug_material(&inv); */
  return (inv);
}
