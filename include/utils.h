/*
** utils.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 14:34:22 2016 Loïc Weinhard
** Last update Sat Jun 18 16:35:08 2016 Loïc Weinhard
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <string.h>

int	isitnum(char *str);
char	**my_str_to_wordtab(char *str, char *delim);
void	free_tab(char **tab);

#endif
