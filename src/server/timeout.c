/*
** timeout.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 25 17:15:27 2016 Loïc Weinhard
** Last update Sat Jun 25 19:23:21 2016 Loïc Weinhard
*/

#include "xfct.h"
#include "server.h"

void			calc_delay(t_pile *pile, struct timeval *delay)
{
  struct timeval	actual;

  gettimeofday(&actual, NULL);
  if (pile == NULL)
    {
      delay->tv_sec = -1;
      delay->tv_usec = -1;
    }
  else
    {
      delay->tv_sec = pile->exec_time - actual.tv_sec;
      delay->tv_usec = 0;
    }
}
