/*
** client_get_lvl1.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Thu Jun 23 12:15:49 2016 Valerian Polizzi
** Last update Sun Jun 26 13:27:07 2016 Valerian Polizzi
*/

#include <client.h>

static void		client_get_lvl1_ext(t_ai **cli, char ***parsing, int *cell)
{
  ai_gauche(*cli);
  *parsing = parse_voir(*cli);
  *cell = look_for_object(*parsing, "linemate");
}

void			client_get_lvl1(t_ai *cli)
{
  int           cell;
  char          **parsing;
  int		rotations;
  char		**required;

  cell = -1;
  parsing = parse_voir(cli);
  while ((cell = look_for_object(parsing, "linemate")) != 0)
    {
      rotations = -1;
      while (cell == -1 && ++rotations < 4)
	client_get_lvl1_ext(&cli, &parsing, &cell);
      if (cell == -1)
	ai_avance(cli);
      else if (cell != 0)
	{
	  ai_count_move(cli, cell);
	  free_tab(parsing);
	  parsing = parse_voir(cli);
	}
    }
  required = my_str_to_wordtab("linemate", "");
  get_rid(cli, required);
  free_tab(parsing);
  free_tab(required);
  ai_incantation(cli, " ");
}
