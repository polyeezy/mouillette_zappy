/*
** get_elems.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 17:47:29 2016 Loïc Weinhard
** Last update Tue Jun 21 17:37:17 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"
#include "map.h"

char	get_elems(t_client player, t_case pos)
{
  char	*tmp;
  char	**materials;
  int	*material;
  int	i;
  char	flags[8];

  if (pos.players != NULL)
    dprintf(player.fd, " player");
  tmp = "food linemate deraumere sibur mendiane phiras thystame";
  materials = my_str_to_wordtab(tmp, " ");
  i = 0;
  memset(flags, 0, 8);
  material = &(pos.materials.food);
  while (i < 7)
    {
      if (*material > 0)
	dprintf(player.fd, " %s", materials[i]);
      i += 1;
      material++;
    }
  free_tab(materials);
  return (0);
}
