/*
** client_get_food.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Sat Jun 25 10:41:33 2016 Valerian Polizzi
** Last update Sat Jun 25 13:13:33 2016 Valerian Polizzi
*/

#include <client.h>

void            client_get_food(t_ai *cli)
{
  int           cell;
  char          **parsing;
  int           rotations;

  cell = -1;
  parsing = NULL;
  parsing = parse_voir(cli);

  while ((cell = look_for_object(parsing, "nourriture")) != 0)
    {
      rotations = 0;
      while (cell == -1 && rotations < 4)
	{
          ai_gauche(cli);
          parsing = parse_voir(cli);
          cell = look_for_object(parsing, "nourriture");
          rotations += 1;
	}
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

