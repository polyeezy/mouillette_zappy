/*
** incantations.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 15:19:45 2016 Loïc Weinhard
** Last update Wed Jun 22 15:25:52 2016 Loïc Weinhard
*/

#include "incantations.h"

t_level	g_levels[LEVELS] =
{
    {
      1,
      {0, 1, 0, 0, 0, 0, 0}
    },
    {
      2,
      {0, 1, 1, 1, 0, 0, 0}
    },
    {
      2,
      {0, 2, 0, 1, 0, 2, 0}
    },
    {
      4,
      {0, 1, 1, 2, 0, 1, 0}
    },
    {
      4,
      {0, 1, 2, 1, 3, 0, 0}
    },
    {
      6,
      {0, 1, 2, 3, 0, 1, 0}
    },
    {
      6,
      {0, 2, 2, 2, 2, 2, 1}
    }
};
