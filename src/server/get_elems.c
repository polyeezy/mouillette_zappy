/*
** get_elems.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 17:47:29 2016 Loïc Weinhard
** Last update Mon Jun 20 20:59:04 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"
#include "map.h"

static char	*concat_all(char flags[9], char **materials, char *str)
{
  int		i;

  i = 0;
  while (materials[i])
    {
      if (flags[i] == 1)
	{
	  str = my_strcat(str, materials[i]);
          str = my_strcat(str, " ");
	}
      i += 1;
    }
  return (str);
}

char	*get_elems(t_case pos, char *str)
{
  char	*tmp;
  char	**materials;
  int	*material;
  int	i;
  char	flags[9];

  tmp = "player(s) food linemate deraumere sibur mendiane phiras thystame";
  materials = my_str_to_wordtab(tmp, " ");
  i = 0;
  material = &(pos.materials.food);
  memset(flags, 0, 9);
  flags[8] = 0;
  if (pos.players != NULL)
    flags[i++] = 1;
  while (i < 8)
    {
      if (*material > 0)
	flags[i] = 1;
      i += 1;
      material += sizeof(int);
    }
  str = concat_all(flags, materials, str);
  free_tab(materials);
  return (str);
}
