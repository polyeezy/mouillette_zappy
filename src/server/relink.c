/*
** norme.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 13:58:37 2016 Loïc Weinhard
** Last update Wed Jun 22 14:02:39 2016 Loïc Weinhard
*/

#include "client.h"

t_client	*relink(t_client *tmp, t_client *player)
{
  if (tmp == NULL)
    {
      tmp = player;
      tmp->prev = NULL;
      tmp->next = NULL;
    }
  else
    {
      tmp->next = player;
      tmp->next->prev = tmp;
      tmp->next->next = NULL;
    }
  return (tmp);
}
