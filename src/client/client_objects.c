/*
** client_objects.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Wed Jun 22 16:00:20 2016 Valerian Polizzi
** Last update Sat Jun 25 18:58:29 2016 Alexis Miele
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
      if (strcmp(epur_str(content[i]), obj) == 0)
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
	  if (strcmp(required[j], epur_str(floor[i])) != 0 &&
	      strcmp(epur_str(floor[i]), "joueur") != 0)
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
      res = object_is_in_cell(epur_str(vision[i]), epur_str(to_find));
      if (res >= 0)
	{
	  printf("--%s FOUND %d--\n", to_find, i);
	  return (i);
	}
     i++;
    }
  return (-1);
}

int		is_in_inventary(t_ai *cli, char *obj)
{
  char		**inv;
  int		i;

  i = 0;
  inv = NULL;
  printf("%s\n", send_and_get(cli, "inventaire"));
  inv = my_str_to_wordtab(cli->last_response, "{ , }");
  while (inv[i])
    {
      if (strcmp(obj, inv[i]) == 0)
	return (1);
      i++;
    }
  return (-1);
}

void		go_get_object(t_ai *cli, char *obj)
{
  int           cell;
  char          **parsing;
  int           rotations;

  cell = -1;
  parsing = NULL;
  parsing = parse_voir(cli);

  while ((cell = look_for_object(parsing, obj)) != 0)
    {
      printf("CELL : %d\n", cell);
      rotations = 0;
      while (cell == -1 && rotations < 4)
        {
          ai_gauche(cli);
          parsing = parse_voir(cli);
          cell = look_for_object(parsing, obj);
	  printf("CELL : %d\n", cell);
	  rotations += 1;
        }
      if (cell == -1)
        ai_avance(cli);
      else
        {
          ai_count_move(cli, cell);
          free_tab(parsing);
          parsing = parse_voir(cli);
        }
    }
  printf("FOUND %s\n", obj);
  ai_prend(cli, obj);
  return;
}
