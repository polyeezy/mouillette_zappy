/*
** client_objects.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Wed Jun 22 16:00:20 2016 Valerian Polizzi
** Last update Sun Jun 26 21:20:12 2016 Aurelie Orset
*/

#include <client.h>
#include <utils.h>
#include <stdlib.h>
#include <args.h>
#include "xfct.h"

void     deblaye(t_ai *cli)
{
  char		**content;
  char		**floor;
  int           i;

  i = 0;
  content = NULL;
  floor = NULL;
  content = parse_voir(cli);
  floor = my_str_to_wordtab(content[0], " ");
  while (floor[i])
    {
      if (strcmp(floor[i], "joueur") != 0
          && strcmp(floor[i], "nourriture") != 0)
        ai_prend(cli, floor[i]);
      i++;
    }
  free_tab(content);
  free_tab(floor);
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
      if (strcmp(content[i], obj) == 0)
	{
	  free_tab(content);
	  return (1);
	}
      i++;
    }
  free_tab(content);
  return (-1);
}

int             look_for_object(char **vision, char *to_find)
{
  int           i;
  int		res;

  i = 0;
  res = 0;
  while (vision[i])
    {
      if (!to_find || !vision[i] || strlen(vision[i]) == 0
	  || strlen(to_find) == 0)
	return (-1);
      res = object_is_in_cell(vision[i], to_find);
      if (res >= 0)
	return (i);
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
      rotations = 0;
      while (cell == -1)
        {
	  rotations < 4 ? ai_avance(cli) : 0;
	  rotations = (rotations < 4 ? 0 : rotations + 1);
	  free_tab(parsing);
	  parsing = parse_voir(cli);
	  cell = look_for_object(parsing, obj);
	}
      ai_count_move(cli, cell);
      free_tab(parsing);
      parsing = parse_voir(cli);
    }
  free_tab(parsing);
  ai_prend(cli, obj);
}
