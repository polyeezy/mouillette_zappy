/*
** musique.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sat Jun 25 17:47:29 2016 Aurelie Orset
** Last update Sun Jun 26 19:05:50 2016 Aurelie Orset
*/

#include "graphic.h"

void	playMusic(char *str, int loops, int div)
{
  Mix_Music *musique;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,\
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    printf("%s", Mix_GetError());
  Mix_VolumeMusic(MIX_MAX_VOLUME / div);
  musique = Mix_LoadMUS(str);
  if (!musique)
    printf("Mix_LoadMUS(%s): %s\n", str, Mix_GetError());
  Mix_PlayMusic(musique, loops);
}
