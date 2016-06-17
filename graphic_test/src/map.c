/*
** map.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:51:40 2016 Aurelie Orset
** Last update Fri Jun 17 16:22:11 2016 Aurelie Orset
*/

#include "map.h"

extern void drawImage(SDL_Surface *, int, int);

void loadMap(char *name)
{
  int x, y;
  FILE *fp;

  fp = fopen(name, "rb");
  if (fp == NULL)
    {
      printf("Failed to open map %s\n", name);
      exit(1);
    }
  for (y=0;y<MAX_MAP_Y;y++)
    {
      for (x=0;x<MAX_MAP_X;x++)
	{
	  fscanf(fp, "%d", &map.tile[y][x]);
	}
    }
  fclose(fp);
}

void drawMap()
{
  int x;
  int y;
  int c; 

  c = 0;
  for (y=0;y<MAX_MAP_Y;y++)
    {
      for (x=0;x<MAX_MAP_X;x++)
	{
	  drawImage(brickImage, x * TILE_SIZE, y * TILE_SIZE);
	}
    }
  for (y=0;y<MAX_MAP_Y;y++)
    {
      for (x=0;x<MAX_MAP_X;x++)
	{
	  if (c == 0)
	    drawImage(n, x * STONE_SIZE, y * STONE_SIZE);
	  else if (c == 1)
	    drawImage(l, x * STONE_SIZE, y * STONE_SIZE);
	  else if (c == 2)
	    drawImage(d, x * STONE_SIZE, y * STONE_SIZE);
	  else if (c == 3)
	    drawImage(s, x * STONE_SIZE, y * STONE_SIZE);
	  else if (c == 4)
	    drawImage(m, x * STONE_SIZE, y * STONE_SIZE);
	  else if (c == 5)
	    drawImage(p, x * STONE_SIZE, y * STONE_SIZE);
	  else
	    {
	      drawImage(t, x * STONE_SIZE, y * STONE_SIZE);
	      c = -1;
	    }
	  c++;
	}
    }	
}
