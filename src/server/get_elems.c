/*
** get_elems.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 17:47:29 2016 Loïc Weinhard
** Last update Sun Jun 26 16:04:41 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"
#include "map.h"

static char	*get_players(t_client *players)
{
  char		*str;
  t_client	*tmp;

  str = NULL;
  tmp = players;
  while (tmp)
    {
      str = my_strcat(str, " joueur");
      tmp = tmp->next;
    }
  return (str);
}

static char	*concat_material(char *str, char *material, int nb)
{
  while (nb > 0)
    {
      str = my_strcat(str, " ");
      str = my_strcat(str, material);
      nb -= 1;
    }
  return (str);
}

char	*get_elems(t_case pos)
{
  char	*tmp;
  char	**materials;
  int	*material;
  int	i;
  char	flags[8];

  tmp = get_players(pos.players);
  materials = my_str_to_wordtab("nourriture linemate deraumere sibur mendiane"
				" phiras thystame", " ");
  i = 0;
  memset(flags, 0, 8);
  material = &(pos.materials.food);
  while (i < 7)
    {
      tmp = concat_material(tmp, materials[i], *material);
      i += 1;
      material++;
    }
  free_tab(materials);
  return (tmp);
}
