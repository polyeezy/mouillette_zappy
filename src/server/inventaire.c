/*
** inventaire.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 21 18:25:01 2016 Loïc Weinhard
** Last update Thu Jun 23 16:57:26 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "cmds.h"
#include "utils.h"

static char	*add_elem_to_str(char *str, char *material, int nb)
{
  char		*nb_str;

  str = my_strcat(str, " ");
  str = my_strcat(str, material);
  str = my_strcat(str, " ");
  str = my_strcat(str, (nb_str = itoa(nb)));
  xfree(nb_str);
  return (str);
}

char	inventaire(t_server *server, t_client *player, char **tab)
{
  char	**materials;
  int	*material;
  int	i;
  char	*str;

  (void)server;
  (void)tab;
  material = &(player->materials.food);
  materials = my_str_to_wordtab("food linemate deraumere sibur mendiane "
				"phiras thystame", " ");
  i = 0;
  str = xstrdup("{");
  while (i < 7)
    {
      if (*material > 0)
	str = add_elem_to_str(str, materials[i], *material);
      i += 1;
      material++;
    }
  str = my_strcat(str, " }\n");
  xwrite(player->fd, str);
  xfree(str);
  free_tab(materials);
  return (0);
}
