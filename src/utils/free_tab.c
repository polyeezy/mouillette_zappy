/*
** free_tab.c for  in /home/weinha_l/Semestre_4/PSU_2015_myirc/src
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
**
** Started on  Mon May 23 19:00:23 2016 Loïc Weinhard
** Last update Sat Jun 18 16:36:19 2016 Loïc Weinhard
*/

#include "utils.h"
#include "xfct.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    xfree(tab[i++]);
  xfree(tab);
}
