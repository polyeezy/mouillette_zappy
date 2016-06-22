/*
** check_syntax.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 14:27:10 2016 Loïc Weinhard
** Last update Wed Jun 22 14:35:42 2016 Loïc Weinhard
*/

#include "args.h"
#include "utils.h"
#include "cmds.h"

int	check_syntax(t_client *player, char **tab)
{
  char	**materials;
  int	i;

  if (lentab(tab) != 2)
    {
      dprintf(player->fd, "ko\n");
      return (-1);
    }
  materials = my_str_to_wordtab("food linemate deraumere sibur mendiane "
				      "phiras thystame", " \n");
  if ((i = get_arg(materials, tab[1])) == -1)
    {
      dprintf(player->fd, "ko\n");
      free_tab(materials);
      return (-1);
    }
  free_tab(materials);
  return (i);
}
