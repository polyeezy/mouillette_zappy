/*
** bct.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 11:29:45 2016 Loïc Weinhard
** Last update Sun Jun 26 11:48:24 2016 Loïc Weinhard
*/

#include "graphic_client.h"
#include "xfct.h"
#include "utils.h"

static char	*create_str(char **tab)
{
  char		*str;

  str = strdup("bct ");
  str = my_strcat(str, tab[1]);
  str = my_strcat(str, " ");
  str = my_strcat(str, tab[2]);
  return (str);
}

static char	sbp_bct(int fd)
{
  xwrite(fd, "sbp\n");
  return (0);
}

char	bct(t_server *server, t_graphic *graphic, char **tab)
{
  char	*str;
  int	*material;
  int	i;
  char	*tmp;

  if (lentab(tab) != 3 || atoi(tab[1]) >= server->width ||
      atoi(tab[2]) >= server->height || atoi(tab[1]) < 0 || atoi(tab[2]) < 0)
    return (sbp_bct(graphic->fd));
  i = -1;
  str = create_str(tab);
  material = &(server->map[atoi(tab[2])][atoi(tab[1])].materials.food);
  while (++i < 7)
    {
      tmp = itoa(*material);
      str = my_strcat(str, " ");
      str = my_strcat(str, tmp);
      xfree(tmp);
      material++;
    }
  str = my_strcat(str, "\n");
  xwrite(graphic->fd, str);
  xfree(str);
  return (0);
}
