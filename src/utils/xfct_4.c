/*
** xfct_4.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/utils/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 16:20:30 2016 Loïc Weinhard
** Last update Sun Jun 26 16:34:52 2016 Loïc Weinhard
*/

#include "xfct.h"

char	*xstrdup(const char *s)
{
  char	*str;

  if ((str = strdup(s)) == NULL)
    exit(fprintf(stderr, "ERROR : strdup() failed\n"));
  return (str);
}
