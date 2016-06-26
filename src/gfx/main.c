/*
** main.c for zappy in /home/oreo/Downloads/tutorial_11/src
** 
** Made by Aurelie Orset
** Login   <orset_a@epitech.net>
** 
** Started on  Fri Jun 17 14:48:10 2016 Aurelie Orset
** Last update Sun Jun 26 15:01:52 2016 Aurelie Orset
*/

#include "args.h"
#include "graphic.h"

SDL_Surface 	*init_screen()
{
  SDL_Surface *load;
  SDL_Surface *screen;

  screen = init("MOUILLETTE ZAPPY", 1500, 1000);
  load = loadImage("gfx/load.png");
  drawImage(load, 0, 0, screen);
  SDL_Flip(screen);
  SDL_Delay(3000);
  SDL_FillRect(screen, NULL, 0x000000);
  SDL_FreeSurface(load);
  return (screen);
}

void	mainLoop(SDL_Surface *screen, int x, int y, t_client_socket client)
{
  unsigned int frameLimit;

  frameLimit = SDL_GetTicks() + 16;
  draw(screen, x, y, client);
  delay(frameLimit);
}

int main(int ac, char **av)
{
  SDL_Surface *screen;
  int	mapx;
  int	mapy;
  t_client_socket client;
  char	**tab;
  char *str;

  ac = ac;
  if (check_args(av) == -1)
    return (-1);
  client = init_client_socket(av);
  str = get_server_response_gfx(&client);
  printf("%s\n", str);
  xfree(str);
  str = send_and_get_gfx(&client, "GRAPHIC");
  tab = my_str_to_wordtab(str, " \n");
  printf("MSZ ? %s\n", str);
  mapx = atoi(tab[1]);
  mapy = atoi(tab[2]);
  screen = init_screen();
  playMusic();
  printf("x %d y %d\n", mapx, mapy);
  while (42)
    mainLoop(screen, mapx, mapy, client);
  xfree(str);
  free_tab(tab);
  return (0);
}
