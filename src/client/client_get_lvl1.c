/*
** client_get_lvl1.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Thu Jun 23 12:15:49 2016 Valerian Polizzi
** Last update Sat Jun 25 15:40:42 2016 Valerian Polizzi
*/

#include <client.h>

void			client_get_lvl1(t_ai *cli)
{
  int           cell;
  char          **parsing;
  int		rotations;

  cell = -1;
  parsing = NULL;
  parsing = parse_voir(cli);

  while ((cell = look_for_object(parsing, "linemate")) != 0)
    {
      rotations = 0;
      while (cell == -1 && rotations < 4)
	{
	  ai_gauche(cli);
	  parsing = parse_voir(cli);
	  cell = look_for_object(parsing, "linemate");
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
  get_rid(cli, my_str_to_wordtab("linemate", ""));
  ai_incantation(cli, " ");
}
