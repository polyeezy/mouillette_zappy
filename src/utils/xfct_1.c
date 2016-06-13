/*
** xfct.c for  in /home/weinha_l/Semestre_4/PSU_2015_myftp/src
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
**
** Started on  Mon May  2 16:31:23 2016 Loïc Weinhard
** Last update	Sat Jun 04 20:16:19 2016 Loïc Weinhard
*/

#include "xfct.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    exit(fprintf(stderr, "ERROR : malloc() failed\n"));
  return (ptr);
}

void	xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}

void	xclose(int fd)
{
  if (close(fd) == -1)
    exit(fprintf(stderr, "ERROR : close() failed\n"));
}

int	xsocket(int domain, int type, int protocol)
{
  int	fd;

  if ((fd = socket(domain, type, protocol)) == -1)
    exit(fprintf(stderr, "ERROR : socket() failed\n"));
  return (fd);
}

int	xgetprotobyname(const char *name)
{
  struct protoent	*proto;

  if (!(proto = getprotobyname(name)))
    exit(fprintf(stderr, "ERROR : getprotobyname() failed\n"));
  return (proto->p_proto);
}
