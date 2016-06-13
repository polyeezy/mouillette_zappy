/*
** isitnum.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 14:34:05 2016 Loïc Weinhard
** Last update Mon Jun 13 15:08:53 2016 Loïc Weinhard
*/

#include "utils.h"

int	isitnum(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i += 1;
    }
  return (0);
}
