/*
** my_strlen.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Thu Jun 23 14:43:52 2016 Loïc Weinhard
** Last update Thu Jun 23 14:44:25 2016 Loïc Weinhard
*/

#include "utils.h"

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
