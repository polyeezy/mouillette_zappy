/*
** graphic.h for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Mon Jun 20 16:34:09 2016 Aurelie Orset
** Last update Thu Jun 23 15:20:33 2016 Aurelie Orset
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>

#define TILE_SIZE 48
#define STONE_SIZE 32

typedef struct	s_tile
{
  int	n;
  int	l;
  int	d;
  int	s;
  int	m;
  int	p;
  int	t;
}		t_tile;

typedef struct s_graph
{
  SDL_Surface *screen;
  SDL_Surface *ground;
  SDL_Surface *n;
  SDL_Surface *l;
  SDL_Surface *d;
  SDL_Surface *s;
  SDL_Surface *m;
  SDL_Surface *p;
  SDL_Surface *t;
  SDL_Surface *nord;
  SDL_Surface *sud;
  SDL_Surface *est;
  SDL_Surface *ouest;
  SDL_Surface *egg;
  SDL_Surface *incant;
  int	map_x;
  int	map_y;
  int	ts; /*TILE SIZE*/
  int	is; /*ITEM SIZE*/
}	      t_graph;

typedef struct	s_info
{
  SDL_Surface *screen;
  SDL_Surface	*n;
  SDL_Surface	*l;
  SDL_Surface	*d;
  SDL_Surface	*s;
  SDL_Surface	*m;
  SDL_Surface	*p;
  SDL_Surface	*t;
  SDL_Surface	*info;
  TTF_Font	*police;
  SDL_Color	color;
}		t_info;

typedef struct	s_player
{
  int			id;
  int			level;
  int			x;
  int			y;
  struct s_payer	*next;
}			t_player;

void		draw();
t_info		*init_info();
t_info		*resize_info(t_info *i, float co);
void		delay(unsigned int frameLimit);
SDL_Surface	*loadImage(char *name);
void		free_all(t_graph *g);
void		free_all_info(t_info *g);
void		drawMap(SDL_Surface *screen, int mapx, int mapy);
void		draw(SDL_Surface *screen, int mapx, int mapy);
void		drawInfo(int x, int y, t_graph *g);
void		drawImage(SDL_Surface *image, int x, int y, SDL_Surface *screen);
SDL_Surface	*init(char *title, int x, int y);
void		getInput();
void		loadMap(char *name);
void		drawCase();

#endif
