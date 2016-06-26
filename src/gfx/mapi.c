/*
** mapi.c for map in /home/oreo/zappy/mouillette_zappy/graphic_test/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Mon Jun 20 17:07:22 2016 Aurelie Orset
** Last update Sun Jun 26 16:02:46 2016 Aurelie Orset
*/

#include "graphic.h"

void	drawGround(t_graph *g)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < g->map_y)
    {
      x = 0;
      while (x < g->map_x)
	{
	  drawImage(g->ground, x * g->ts, y * g->ts, g->screen);
	  x++;
	}
      y++;
    }
}

void	drawStones(t_graph *g, t_tile *tl, int x, int y)
{
  if (tl->n > 0)
    drawImage(g->n, x * g->ts, y * g->ts, g->screen);
  if (tl->l > 0)
    drawImage(g->l, (x * g->ts) + g->is, y * g->ts, g->screen);
  if (tl->d > 0)
    drawImage(g->d, (x * g->ts) + (2 * g->is), y * g->ts, g->screen);
  if (tl->s > 0)
    drawImage(g->s, x * g->ts, (y * g->ts) + g->is, g->screen);
  if (tl->m > 0)
    drawImage(g->m, (x * g->ts) + g->is, (y * g->ts) + g->is, g->screen);
  if (tl->p > 0)
    drawImage(g->p, x * g->ts + 2 * g->is, y * g->ts + g->is, g->screen);
  if (tl->t > 0)
    drawImage(g->t, x * g->ts, (y * g->ts) + (2* g->is), g->screen);
}

void	drawAll(int x, int y, t_client_socket client, t_graph *g)
{
  t_tile	*tl;
  char str[15];
  char *str1;

  tl = xmalloc(sizeof(t_tile));
  sprintf(str, "bct %d %d", x, y);
  str1 = send_and_get_gfx(&client, str);
  usleep(10);
  tl = ressources(tl, str1);
  drawStones(g, tl, x, y);
  xfree(str1);
  xfree(tl);
}

void drawMap(SDL_Surface *screen, int mapx, int mapy, t_client_socket client)
{
  int	x;
  int	y;
  t_graph	*g;

  g = init_graph(mapx, mapy, screen);
  g = resize(g, calcCo(mapx, mapy, g));
  drawGround(g);
  y = 0;
  while (y < g->map_y)
    {
      x = 0;
      while (x < g->map_x)
	{
	  drawAll(x, y, client, g);
	  x++;
	}
      y++;
    }
  usleep(100);
  drawPlayers(g, client);
  usleep(100);
  drawInfo(0, 0, g, client);
  free_all(g);
}
