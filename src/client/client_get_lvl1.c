/*
** client_get_lvl1.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Thu Jun 23 12:15:49 2016 Valerian Polizzi
** Last update Sat Jun 25 18:57:09 2016 Alexis Miele
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

  cell = -1;
  parsing = parse_voir(cli);
  while ((cell = look_for_object(parsing, "linemate")) != 0)
    {
      rotations = -1;
      while (cell == -1 && ++rotations < 4)
	client_get_lvl1_ext(&cli, &parsing, &cell);
      if (cell == -1)
	ai_avance(cli);
      else
	{
	  ai_count_move(cli, cell);
	  free_tab(parsing);
	  parsing = parse_voir(cli);
	}
    }
  get_rid(cli, my_str_to_wordtab("linemate", ""));
  ai_incantation(cli, " ");
}
