/*
** graphic.h for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Mon Jun 20 16:34:09 2016 Aurelie Orset
** Last update Sun Jun 26 21:25:32 2016 Aurelie Orset
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <SDL/SDL_mixer.h>
# include <unistd.h>
# include <netinet/in.h>
# include <utils.h>
# include <string.h>
# include <ai_cmd.h>
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_rotozoom.h>
# include <SDL/SDL_ttf.h>
# include <stdio.h>
# include "client.h"
# include "xfct.h"

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
  SDL_Surface *nord2;
  SDL_Surface *sud2;
  SDL_Surface *est2;
  SDL_Surface *ouest2;
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

typedef struct s_coord
{
  int x;
  int y;
  int lvl;
  int id;
}		t_coord;

float		calcCo(int mapy, int mapx, t_graph *g);
int		convertX(int x, t_graph *g);
int		compareID(int l, int x, int y, char **tab);

void		delay(unsigned int frameLimit);
void		draw(SDL_Surface *screen, int mapx, int mapy,
		     t_client_socket client);
void		drawAll(int x, int y, t_client_socket client, t_graph *g);
void		drawCase();
void		drawCoord(t_info *i, t_graph *g, int x, int y);
void		drawFood(t_info *i, int x, int y, t_client_socket client);
void		drawGround(t_graph *g);
void		drawImage(SDL_Surface *image, int x, int y, SDL_Surface *screen);
void		drawInfo(int x, int y, t_graph *g, t_client_socket client);
void		drawInventaire(t_graph *g, t_client_socket client);
void		drawInventPlayer(t_info *i, t_graph *g, char **tab);
void		drawMap(SDL_Surface *screen, int mapx, int mapy,
			t_client_socket client);
void		drawOrient(t_graph *g, int x, char **tab);
void		drawOrient2(t_graph *g, int x, char **tab);
void		drawPlayer(t_info *i, t_graph *g, t_client_socket client);
void		drawPlayers(t_graph *g, t_client_socket client);
void		drawStones(t_graph *g, t_tile *tl, int x, int y);
void		drawTexte(t_info *i, int x, int y, char *str);

void		free_all(t_graph *g);
void		free_all_info(t_info *g);
void		*free_at_exit(t_graph *g, t_info *i);

int		getID(t_client_socket client, t_graph *g);
void		getInput();
int		getLvl(t_client_socket client, int id);
char            *get_server_response_gfx(t_client_socket *cli);
char		**getToParse(t_client_socket client);

SDL_Surface	*init(char *title, int x, int y);
t_info		*init_and_resize(t_graph *g);
t_client_socket	 init_client_socket(char **argv);
t_graph		*init_graph(int x, int y, SDL_Surface *screen);
char		**init_id_tab(t_client_socket client);
t_info		*init_info(t_graph *g);
t_graph		*init_nemesis(t_graph *g);
SDL_Surface 	*init_screen();

SDL_Surface	*loadImage(char *name);

void		mainLoop(SDL_Surface *screen, int x, int y,
			 t_client_socket client);

void		playMusic(char *str, int loops, int div);

t_graph		*resize(t_graph *g, float co);
t_info		*resize_info(t_info *i, float co);
t_tile		*ressources(t_tile *tile, char *str);

char		*send_and_get_gfx(t_client_socket *cli, char *cmd);
int             send_cmd_server_gfx(t_client_socket *cli, char *msg);

#endif
