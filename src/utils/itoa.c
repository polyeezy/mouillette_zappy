/*
** itoa.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Thu Jun 23 16:20:04 2016 Loïc Weinhard
** Last update Thu Jun 23 16:46:03 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "utils.h"

char	*itoa(int nb)
{
  char	*str;
  int	length;
  int	divi;
  int	i;

  divi = 1;
  length = 0;
  str = NULL;
  while (++length && nb / divi > 9)
    divi *= 10;
  str = xmalloc(length + 1);
  i = 0;
  while (i < length)
    {
      str[i++] = 48 + (nb / divi);
      nb %= divi;
      divi /= 10;
    }
  str[i] = 0;
  return (str);
}
