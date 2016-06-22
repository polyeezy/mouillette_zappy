/*
** info.c for zappy in /home/oreo/zappy/mouillette_zappy/graphic_test
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Wed Jun 22 14:18:08 2016 Aurelie Orset
** Last update Wed Jun 22 15:33:31 2016 Aurelie Orset
*/

#include "graphic.h"

int	convertX(int x, t_graph *g)
{
  double calc;

  calc = (x / g->ts);
  x = calc;
  return (x+1);
}

void	drawInfo(int x, int y, t_graph *g)
{
  TTF_Font *police;
  SDL_Color color = {255,34,12};
  SDL_Surface *texte;
  SDL_Surface *texte2;
  SDL_Surface *texte3;
  SDL_Event event;
  char str[17];
  char str1[17];

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  SDL_GetMouseState(&x, &y);
	  x = convertX(x, g);
	  y = convertX(y, g);
	  sprintf(str, "x %d", x);
	  sprintf(str1, "y %d", y);
	  if ((police = TTF_OpenFont("gfx/font.ttf", 65)) == NULL)
	    printf("no load\n");
	  drawImage(g->info, 1000, 0, g->screen);
	  texte = TTF_RenderText_Solid(police, "INFO", color);
	  texte2 = TTF_RenderText_Solid(police, str, color);
	  texte3 = TTF_RenderText_Solid(police, str1, color);
	  drawImage(texte, 1205, 10, g->screen);
	  drawImage(texte2, 1205, 80, g->screen);
	  drawImage(texte3, 1205, 160, g->screen);
	  TTF_CloseFont(police);
	  SDL_FreeSurface(texte);
	  SDL_FreeSurface(texte2);
	  SDL_FreeSurface(texte3);
	}
      if(event.type == SDL_QUIT)
	exit(0);
    }
}

