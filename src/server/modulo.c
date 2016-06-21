/*
** modulo.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 20 16:02:56 2016 Loïc Weinhard
** Last update Mon Jun 20 16:06:11 2016 Loïc Weinhard
*/

#include "map.h"

int	mod(int pos, int max)
{
  if (pos < 0)
    return (max - 1);
  else
    return (pos % max);
}
