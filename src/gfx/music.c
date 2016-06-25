/*
** musique.c for zappy in /home/orset_a/tek2/zappy/mouillette_zappy
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Sat Jun 25 17:47:29 2016 Aurelie Orset
** Last update Sat Jun 25 18:09:24 2016 Aurelie Orset
*/

#include "graphic.h"

void	playMusic()
{
  Mix_Music *musique;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,\
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    printf("%s", Mix_GetError());
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
  musique = Mix_LoadMUS("gfx/waka.wav");
  if (!musique)
    {
      printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
    }
  Mix_PlayMusic(musique, -1);
}
