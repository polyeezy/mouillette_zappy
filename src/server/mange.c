/*
** eat.c for eat in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 12:54:38 2016 Alexis Miele
** Last update Sun Jun 26 16:09:43 2016 Alexis Miele
*/

#include "cmds.h"
#include "xfct.h"

char	mange(t_server *server, t_client *player, char **tab)
{
  (void)tab;
  if ((player->materials.food -= 1) <= 0)
    {
      xwrite(player->fd, "mort\n");
      remove_client(server, player, 0);
    }
  else
    pre_mange(server, player, "mange",
	      &(g_cmds[NUMBER_OF_COMMANDS - 1]));
  return (0);
}
