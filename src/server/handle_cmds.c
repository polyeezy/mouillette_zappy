/*
** handle_cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:11:57 2016 Loïc Weinhard
** Last update Sun Jun 26 16:42:42 2016 Loïc Weinhard
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
  while (i < NUMBER_OF_COMMANDS - 1)
    {
      if (strcmp(g_cmds[i].name, tab[0]) == 0)
	g_cmds[i].pre_func(server, player, buffer, &g_cmds[i]);
      i += 1;
    }
  free_tab(tab);
}
