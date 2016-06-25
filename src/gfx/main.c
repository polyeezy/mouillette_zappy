/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Sat Jun 25 17:18:06 2016 Aurelie Orset
*/

#include "args.h"
#include "graphic.h"

int main(int ac, char **av)
{
  unsigned int frameLimit = SDL_GetTicks() + 16;
  SDL_Surface *screen;
  SDL_Surface *load;
  int	mapx;
  int	mapy;
  Mix_Music *musique; //Création d'un pointeur de type Mix_Music
  t_client_socket client;
  char	**tab;
  char *str;

  Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
  musique = Mix_LoadMUS("gfx/musique.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1);

  ac = ac;
  if (check_args(av) == -1)
    return (-1);
  client = init_client_socket(av);
  printf("%s\n", get_server_response_gfx(&client));
  str = send_and_get_gfx(&client, "GRAPHIC");
  tab = my_str_to_wordtab(str, " ");
  mapx = atoi(tab[1]);
  mapy = atoi(tab[2]);
  screen = init("MOUILLETTE ZAPPY", 1500, 1000);
  load = loadImage("gfx/load.png");
  drawImage(load, 0, 0, screen);
  SDL_Flip(screen);
  SDL_Delay(1);
  SDL_FillRect(screen, NULL, 0x000000);
  while (42)
  {
    draw(screen, mapx, mapy, client);
    delay(frameLimit);
    frameLimit = SDL_GetTicks() + 16;
  }
  return (0);
}
