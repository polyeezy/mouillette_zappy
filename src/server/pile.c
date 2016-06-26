/*
** pile.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Fri Jun 24 14:57:02 2016 Loïc Weinhard
** Last update Sun Jun 26 11:13:53 2016 Alexis Miele
*/

#include "pile.h"
#include "xfct.h"
#include "utils.h"

void			exec_pile(t_server *server, t_pile **pile)
{
  char			**tab;
  struct timeval	timinho;

  gettimeofday(&timinho, NULL);
  while (*pile && timinho.tv_sec >= (*pile)->exec_time)
    {
      tab = my_str_to_wordtab((*pile)->cmd, " \n");
      (*pile)->player != NULL ?
	(*pile)->func->ptr_func(server, (*pile)->player, tab) : 0;
      free_tab(tab);
      if ((*pile)->next == NULL)
	{
	  xfree((*pile)->cmd);
	  xfree(*pile);
	  *pile = NULL;
	}
      else
	{
	  *pile = (*pile)->next;
	  xfree((*pile)->prev->cmd);
	  xfree((*pile)->prev);
	  (*pile)->prev = NULL;
	}
    }
}

static void		new_pile(t_pile **pile, t_pile **new)
{
  (*new)->next = NULL;
  (*new)->prev = NULL;
  *pile = *new;
}

static void		add_elem_to_pile(t_pile **pile, t_pile **new)
{
  t_pile		*tmp;

  tmp = *pile;
  while (tmp->next && ((*new)->exec_time > tmp->exec_time))
    tmp = tmp->next;
  if ((*new)->exec_time < tmp->exec_time)
    {
      (*new)->prev = tmp->prev;
      (*new)->next = tmp;
      if (tmp->prev != NULL)
	tmp->prev->next = *new;
      tmp->prev = *new;
      *pile = (tmp == *pile ? *new : *pile);
    }
  else
    {
      (*new)->prev = tmp;
      (*new)->next = tmp->next;
      if ((*new)->next != NULL)
	(*new)->next->prev = *new;
      tmp->next = *new;
    }
}

static int		check_size_pile(t_pile *pile, t_client *player)
{
  int			i;

  i = 0;
  while (pile)
    {
      if (pile->player && pile->player->fd == player->fd)
	i++;
      pile = pile->next;
    }
  return (i);
}

void			add_pile(t_server *server,
			 t_client *player, char *buff, t_cmd *cmd)
{
  t_pile		*elem;
  struct timeval	actual;

  gettimeofday(&actual, NULL);
  elem = xmalloc(sizeof(t_pile));
  elem->cmd = buff;
  elem->player = player;
  elem->func = cmd;
  elem->exec_time = actual.tv_sec +
      (long long int)(cmd->delay * (1 / (float)server->timeout));
  if (server->pile == NULL)
    new_pile(&(server->pile), &elem);
  else if (check_size_pile(server->pile, player) <= 11)
    add_elem_to_pile(&(server->pile), &elem);
  else
    {
      xfree(elem->cmd);
      xfree(elem);
    }
}
