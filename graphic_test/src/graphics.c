/*
** graphics.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:46:25 2016 Aurelie Orset
** Last update Wed Jun 22 16:15:16 2016 Aurelie Orset
*/

#include "graphic.h"

SDL_Surface *loadImage(char *name)
{
  SDL_Surface *temp = IMG_Load(name);
  SDL_Surface *image;

  if (temp == NULL)
    {
      printf("Failed to load image %s\n", name);
      return NULL;
    }
  SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL),\
		  SDL_MapRGB(temp->format, 0, 0, 0));
  image = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  if (image == NULL)
    {
      printf("Failed to convert image %s to native format\n", name);
      return NULL;
    }
  return image;
}

void drawImage(SDL_Surface *image, int x, int y, SDL_Surface *screen)
{
  SDL_Rect dest;

  dest.x = x;
  dest.y = y;
  dest.w = image->w;
  dest.h = image->h;
  SDL_BlitSurface(image, NULL, screen, &dest);
}

