/*
** mapi.c for map in /home/oreo/zappy/mouillette_zappy/graphic_test/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Mon Jun 20 17:07:22 2016 Aurelie Orset
** Last update Thu Jun 23 21:08:11 2016 Aurelie Orset
*/

#include "graphic.h"

t_tile	*ressources(t_tile *tile, char *str)
{
  char **tab;

  tab = my_str_to_wordtab(str, " \n");
  tile->n = atoi(tab[3]);
  tile->l = atoi(tab[4]);
  tile->d = atoi(tab[5]);
  tile->s = atoi(tab[6]);
  tile->m = atoi(tab[7]);
  tile->p = atoi(tab[8]);
  tile->t = atoi(tab[9]);
  return (tile);
}

t_graph *resize(t_graph *g, float co)
{
  g->ground = rotozoomSurface(g->ground, 0.0, co, 1);
  g->n = rotozoomSurface(g->n, 0.0, co, 1);
  g->l = rotozoomSurface(g->l, 0.0, co, 1);
  g->d = rotozoomSurface(g->d, 0.0, co, 1);
  g->s = rotozoomSurface(g->s, 0.0, co, 1);
  g->m = rotozoomSurface(g->m, 0.0, co, 1);
  g->p = rotozoomSurface(g->p, 0.0, co, 1);
  g->t = rotozoomSurface(g->t, 0.0, co, 1);
  g->nord = rotozoomSurface(g->nord, 0.0, co, 1);
  g->sud = rotozoomSurface(g->sud, 0.0, co, 1);
  g->est = rotozoomSurface(g->est, 0.0, co, 1);
  g->ouest = rotozoomSurface(g->ouest, 0.0, co, 1);
  g->egg = rotozoomSurface(g->egg, 0.0, co, 1);
  g->incant = rotozoomSurface(g->incant, 0.0, co, 1);
  g->is = g->is * co;
  g->ts = g->ts * co;
  return (g);
}

t_graph	*init_graph(int x, int y, SDL_Surface *screen)
{
  t_graph *g;

  g = malloc(sizeof(t_graph));
  g->map_x = x;
  g->map_y = y;
  g->ground = loadImage("gfx/grass.jpg");
  g->n = loadImage("gfx/cake.png");
  g->l = loadImage("gfx/linemate_small.png");
  g->d = loadImage("gfx/deraumire_small.png");
  g->s = loadImage("gfx/sibur_small.png");
  g->m = loadImage("gfx/mendiane_small.png");
  g->p = loadImage("gfx/phiras_small.png");
  g->t = loadImage("gfx/thystame_small.png");
  g->nord = loadImage("gfx/nord.png");
  g->sud = loadImage("gfx/sud.png");
  g->est = loadImage("gfx/est.png");
  g->ouest = loadImage("gfx/ouest.png");
  g->egg = loadImage("gfx/egg.png");
  g->incant = loadImage("gfx/incant.png");
  g->screen = screen;
  g->is = 32;
  g->ts = 96;
  return (g);
}

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

void drawMap(SDL_Surface *screen, int mapx, int mapy, t_client_socket client)
{
  int	x;
  int	y;
  t_tile	*tl;
  t_graph	*g;
  int		calc;
  float co;
  /*char	**tab;*/
  char	*str;

  tl = malloc(sizeof(t_tile));
  str = malloc(sizeof(char) * 255);
  g = init_graph(mapx, mapy, screen);
  y = 0;
  calc = mapx;
  if (calc < mapy)
    calc = mapy;
  co = 1000 / calc;
  co /= g->ts;
  g = resize(g, co);
  drawGround(g);
  while (y < g->map_y)
    {
      x = 0;
      while (x < g->map_x)
	{
	  sprintf(str, "bct %d %d", x, y);
	  /*printf("str : %s\n", str);*/
	  str = send_and_get_gfx(&client, str);
	  printf("%s\n", str);
	  tl = ressources(tl, str);
	  /*REQUETE SERVEUR POUR RECUP LES DONNEEES DE LA MAP*/
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
	  /*REQUETE SERVEUR POUR LES PERSOS ET LES OEUFS*/
	  x++;
	}
      y++;
    }
  drawInfo(0, 0, g, client);
  free(tl);
  free_all(g);
}
