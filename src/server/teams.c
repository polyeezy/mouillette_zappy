/*
** teams.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:39:57 2016 Loïc Weinhard
** Last update Mon Jun 13 16:47:38 2016 Loïc Weinhard
*/

#include "args.h"
#include "utils.h"
#include "team.h"
#include "xfct.h"
#include "client.h"

void	free_teams(t_team *teams)
{
  while (teams != NULL)
    {
      xfree(teams->name);
      free_clients(teams->members);
      if (teams->next != NULL)
	{
	  teams = teams->next;
	  xfree(teams->prev);
	}
      else
	xfree(teams);
    }
}

void	add_teams(t_team **teams, char **argv)
{
  *teams = xmalloc(sizeof(t_team));
  (*teams)->name = strdup(argv[get_arg(argv, "-n") + 1]);
  (*teams)->max = atoi(argv[get_arg(argv, "-c") + 1]);
  (*teams)->members = NULL;
  (*teams)->prev = NULL;
  (*teams)->next = xmalloc(sizeof(t_team));
  (*teams)->next->name = strdup(argv[get_arg(argv, "-n") + 2]);
  (*teams)->next->max = atoi(argv[get_arg(argv, "-c") + 1]);
  (*teams)->next->members = NULL;
  (*teams)->next->prev = *teams;
  (*teams)->next->next = NULL;
}
