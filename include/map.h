/*
** map.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 14 16:04:41 2016 Loïc Weinhard
** Last update Fri Jun 17 12:09:31 2016 Loïc Weinhard
*/

#ifndef MAP_H_
# define MAP_H_

# include "materials.h"

typedef struct	s_case
{
  t_client	*players;
  t_materials	materials;
}		t_case;

#endif