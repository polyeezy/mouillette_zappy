/*
** my_strcat.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 18:19:49 2016 Loïc Weinhard
** Last update Mon Jun 20 20:13:54 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"

char	*my_strcat(char *src, char *tocat)
{
  char	*tmp;
  int	length;
  int	i;
  int	x;

  tmp = strdup(src);
  length = strlen(src) + strlen(tocat) + 1;
  xfree(src);
  src = xmalloc(length);
  i = 0;
  x = 0;
  while ((size_t)i < strlen(tmp))
    src[i++] = tmp[x++];
  x = 0;
  while ((size_t)x < strlen(tocat))
    src[i++] = tocat[x++];
  src[i] = 0;
  return (src);
}
