/*
** graphic.h for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Mon Jun 20 16:34:09 2016 Aurelie Orset
** Last update Tue Jun 21 16:55:08 2016 Aurelie Orset
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

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
  int	map_x;
  int	map_y;
  int	tile_size;
  int	stone_size;
}	      t_graph;

void	draw();
void	delay(unsigned int frameLimit);
SDL_Surface *loadImage(char *name);
void drawMap();
void drawImage(SDL_Surface *image, int x, int y, SDL_Surface *screen);
SDL_Surface *init(char *title);
void getInput();
void loadMap(char *name);

#endif
