/*
** norme.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Wed Jun 22 13:58:37 2016 Loïc Weinhard
** Last update Sat Jun 25 14:31:41 2016 Alexis Miele
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
      player->next = tmp->next;
      tmp->next = player;
      player->prev = tmp;
    }
  return (tmp);
}

void     add_player_on_map(t_client **player, t_client **new)
{
  t_client      *tmp;

  if (*player == NULL)
    {
      *player = *new;
      (*player)->next = NULL;
      (*player)->prev = NULL;
    }
  else
    {
      tmp = *player;
      while (tmp && tmp->next)
        tmp = tmp->next;
      tmp->next = *new;
      (*new)->prev = tmp;
      (*new)->next = NULL;
    }
}
