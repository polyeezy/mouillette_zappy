/*
** client_get_food.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
**
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
**
** Started on  Sat Jun 25 10:41:33 2016 Valerian Polizzi
** Last update Sat Jun 25 18:53:37 2016 Alexis Miele
*/

#include <client.h>

static void	client_get_food_ext(t_ai **cli, char ***parsing, int *cell)
{
  ai_gauche(*cli);
  *parsing = parse_voir(*cli);
  *cell = look_for_object(*parsing, "nourriture");
}

void            client_get_food(t_ai *cli)
{
  int           cell;
  char          **parsing;
  int           rotations;

  cell = -1;
  parsing = parse_voir(cli);
  while ((cell = look_for_object(parsing, "nourriture")) != 0)
    {
      rotations = -1;
      while (cell == -1 && ++rotations < 4)
	client_get_food_ext(&cli, &parsing, &cell);
      if (cell == -1)
	ai_avance(cli);
      else if (cell == 0)
	ai_prend(cli, "nourriture");
      else
        {
	  ai_count_move(cli, cell);
          free_tab(parsing);
          parsing = parse_voir(cli);
	}
    }
  ai_prend(cli, "nourriture");
}
