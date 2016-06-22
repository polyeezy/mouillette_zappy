/*
** lentab.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 14:12:03 2016 Loïc Weinhard
** Last update Wed Jun 22 14:12:39 2016 Loïc Weinhard
*/

#include "utils.h"

int	lentab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i])
    i += 1;
  return (i);
}
