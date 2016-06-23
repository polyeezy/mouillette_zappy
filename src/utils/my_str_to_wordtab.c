/*
** my_str_to_wordtab.c for  in /home/guarni_l/rendu/PSU_2014_42sh/lib
** 
** Made by luca guarnieri
** Login   <guarni_l@epitech.net>
** 
** Started on  Sun May 24 14:55:48 2015 luca guarnieri
** Last update Wed Jun 22 11:08:53 2016 Valerian Polizzi
*/

#include "xfct.h"
#include <args.h>

static int	parser(char c, char *separators)
{
  int		i;

  i = 0;
  while (separators[i])
    {
      if (separators[i] == c)
	return (0);
      i = i + 1;
    }
  return (1);
}

static int	count_words(char *str, char *separators)
{
  int		i;
  int		words;

  i = 0;
  words = 1;
  while (str[i])
    {
      if (parser(str[i], separators) == 0)
	{
	  words = words + 1;
	  while (parser(str[i], separators) == 0 && str[i])
	    i = i + 1;
	}
      else
	i = i + 1;
    }
  return (words + 1);
}

static int	count_letters(char *str, int i, char *separators)
{
  int		old_i;

  old_i = i;
  while (parser(str[i], separators) == 1 && str[i])
    i = i + 1;
  return (i - old_i + 1);
}

char		**my_str_to_wordtab(char *str, char *separators)
{
  char		**tab;
  int		i;
  int		x;
  int		y;

  i = 0;
  x = 0;
  if (str == NULL)
    return (NULL);
  tab = xmalloc(count_words(str, separators) * sizeof(char *));
  while (parser(str[i], separators) == 0)
    i = i + 1;
  while (str[i])
    {
      y = 0;
      tab[x] = xmalloc(count_letters(str, i, separators) * sizeof(char));
      while (parser(str[i], separators) == 1 && str[i])
	tab[x][y++] = str[i++];
      tab[x][y] = '\0';
      while (parser(str[i], separators) == 0 && str[i])
	i = i + 1;
      x = x + 1;
    }
  tab[x] = '\0';
  return (tab);
}
