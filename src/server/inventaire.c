/*
** inventaire.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 21 18:25:01 2016 Loïc Weinhard
** Last update Tue Jun 21 18:34:41 2016 Loïc Weinhard
*/

#include "cmds.h"
#include "utils.h"

char	inventaire(t_server *server, t_client *player, char **tab)
{
  char	**materials;
  int	*material;
  int	i;

  (void)server;
  (void)tab;
  material = &(player->materials.food);
  materials = my_str_to_wordtab("food linemate deraumere sibur mendiane "
				"phiras thystame", " ");
  i = 0;
  dprintf(player->fd, "{");
  while (i < 7)
    {
      if (*material > 0)
	dprintf(player->fd, " %s %d", materials[i], *material);
      i += 1;
      material++;
    }
  dprintf(player->fd, " }\n");
  free_tab(materials);
  return (0);
}
