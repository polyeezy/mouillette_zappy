/*
** incantations.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 15:17:29 2016 Loïc Weinhard
** Last update Wed Jun 22 15:20:23 2016 Loïc Weinhard
*/

#ifndef INCANTATIONS_H_
# define INCANTATIONS_H_

# include "materials.h"

# define LEVELS 7

typedef struct	s_level
{
  int		players;
  t_materials	materials;
}		t_level;

extern t_level	g_levels[LEVELS];

#endif
