/*
** get_elems.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 17:47:29 2016 Loïc Weinhard
** Last update Thu Jun 23 14:50:57 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"
#include "map.h"

char	*get_elems(t_case pos)
{
  char	*tmp;
  char	**materials;
  int	*material;
  int	i;
  char	flags[8];

  tmp = (pos.players != NULL ? strdup(" player") : NULL);
  materials = my_str_to_wordtab("food linemate deraumere sibur mendiane phiras"
				" thystame", " ");
  i = 0;
  memset(flags, 0, 8);
  material = &(pos.materials.food);
  while (i < 7)
    {
      if (*material > 0)
	{
	  tmp = my_strcat(tmp, " ");
	  tmp = my_strcat(tmp, materials[i]);
	}
      i += 1;
      material++;
    }
  free_tab(materials);
  return (tmp);
}
