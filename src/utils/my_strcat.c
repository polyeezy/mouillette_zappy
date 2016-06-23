/*
** my_strcat.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 18:19:49 2016 Loïc Weinhard
** Last update Thu Jun 23 15:03:02 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"

char	*my_strcat(char *src, char *tocat)
{
  char	*tmp;
  int	length;
  int	i;
  int	x;

  tmp = (src != NULL ? strdup(src) : NULL);
  length = my_strlen(src) + my_strlen(tocat) + 1;
  xfree(src);
  src = xmalloc(length);
  i = 0;
  x = 0;
  while (i < my_strlen(tmp))
    src[i++] = tmp[x++];
  x = 0;
  while (x < my_strlen(tocat))
    src[i++] = tocat[x++];
  src[i] = 0;
  return (src);
}
