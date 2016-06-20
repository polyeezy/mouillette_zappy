/*
** map.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 14 16:04:41 2016 Loïc Weinhard
** Last update Mon Jun 20 21:22:04 2016 Loïc Weinhard
*/

#ifndef MAP_H_
# define MAP_H_

# include "materials.h"
# include "client.h"

typedef struct	s_case
{
  t_client	*players;
  t_materials	materials;
}		t_case;

int	mod(int pos, int max);
char	get_elems(t_client player, t_case pos);

#endif
