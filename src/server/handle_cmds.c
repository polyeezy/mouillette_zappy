/*
** handle_cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:11:57 2016 Loïc Weinhard
** Last update Fri Jun 24 15:51:49 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "cmds.h"
#include "utils.h"
#include "pile.h"

void	handle_cmds(t_server *server, t_client *player)
{
  char	buffer[4097];
  int	ret;
  char	**tab;
  int	i;
  t_pile	*pile;

  i = 0;
  ret = xread(player->fd, buffer, 4096);
  if (ret == 0 || ret == 1)
    {
      remove_client(server, player, ret);
      return;
    }
  buffer[ret] = 0;
  printf("Player %d sent : [%.*s]\n", player->fd,
	 my_strlen(buffer) - 1, buffer);
  tab = my_str_to_wordtab(buffer, " \t\r\n");
  while (i < NUMBER_OF_COMMANDS)
    {
      if (strcmp(g_cmds[i].name, tab[0]) == 0)
	add_pile(server, player, buffer, g_cmds[i]);
      i += 1;
    }
  pile = server->pile;
  while (pile)
    {
      printf("%s", pile->cmd);
      pile = pile->next;
    }
  free_tab(tab);
}
