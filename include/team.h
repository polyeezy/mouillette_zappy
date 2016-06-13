/*
** team.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:23:48 2016 Loïc Weinhard
** Last update Mon Jun 13 16:46:20 2016 Loïc Weinhard
*/

#ifndef TEAM_H_
# define TEAM_H_

# include "client.h"

typedef struct	s_team
{
  char		*name;
  int		max;
  t_client	*members;
  struct s_team	*next;
  struct s_team	*prev;
}		t_team;

void	add_teams(t_team **teams, char **argv);
void	free_teams(t_team *teams);

#endif
