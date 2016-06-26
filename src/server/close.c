/*
** close.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:11:05 2016 Loïc Weinhard
** Last update Sun Jun 26 21:29:08 2016 Aurelie Orset
*/

#include "xfct.h"
#include "server.h"

void	free_map(t_case **map)
{
  int	i;

  i = 0;
  while (map[i])
    xfree(map[i++]);
  xfree(map);
}

static void	free_graphics(t_graphic *graphics)
{
  while (graphics != NULL)
    {
      xclose(graphics->fd);
      if (graphics->next != NULL)
	{
	  graphics = graphics->next;
	  xfree(graphics->prev);
	  graphics->prev = NULL;
	}
      else
	{
	  xfree(graphics);
	  graphics = NULL;
	}
    }
}

int	close_server(t_server server)
{
  xclose(server.fd);
  free_teams(server.teams);
  free_map(server.map);
  free_graphics(server.graphic);
  return (0);
}
