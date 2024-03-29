/*
** teams.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 16:39:57 2016 Loïc Weinhard
** Last update Sun Jun 26 21:21:15 2016 Aurelie Orset
*/

#include "args.h"
#include "utils.h"
#include "team.h"
#include "xfct.h"
#include "client.h"

void	free_teams(t_team *teams)
{
  while (teams->next != NULL)
    {
      xfree(teams->name);
      free_clients(teams->members);
      teams = teams->next;
      xfree(teams->prev);
      teams->prev = NULL;
    }
  xfree(teams->name);
  free_clients(teams->members);
  xfree(teams);
  teams = NULL;
}

int	add_teams(t_team **teams, char **argv)
{
  if (strcmp(argv[get_arg(argv, "-n") + 1], "GRAPHIC") == 0 ||
      strcmp(argv[get_arg(argv, "-n") + 2], "GRAPHIC") == 0 ||
      strcmp(argv[get_arg(argv, "-n") + 1],
	     argv[get_arg(argv, "-n") + 2]) == 0)
     return (-1);
  *teams = xmalloc(sizeof(t_team));
  (*teams)->name = xstrdup(argv[get_arg(argv, "-n") + 1]);
  (*teams)->max = atoi(argv[get_arg(argv, "-c") + 1]);
  (*teams)->members = NULL;
  (*teams)->prev = NULL;
  (*teams)->next = xmalloc(sizeof(t_team));
  (*teams)->next->name = xstrdup(argv[get_arg(argv, "-n") + 2]);
  (*teams)->next->max = atoi(argv[get_arg(argv, "-c") + 1]);
  (*teams)->next->members = NULL;
  (*teams)->next->prev = *teams;
  (*teams)->next->next = NULL;
  return (0);
}
