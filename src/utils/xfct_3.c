/*
** xfct_3.c for  in /home/weinha_l/Semestre_4/PSU_2015_myftp/src
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
**
** Started on  Thu May  5 13:54:58 2016 Loïc Weinhard
** Last update	Fri Jun 03 13:05:47 2016 Loïc Weinhard
*/

#include <string.h>
#include "utils.h"
#include "xfct.h"

ssize_t		xread(int fd, void *buf, size_t count)
{
  ssize_t	i;

  if ((i = read(fd, buf, count)) == -1)
    exit(fprintf(stderr, "ERROR : read() failed\n"));
  return (i);
}

int	xselect(int nfds, fd_set *read, fd_set *write,
		fd_set *except, struct timeval *time)
{
  int	i;

  if ((i = select(nfds, read, write, except, time)) == -1)
    exit(fprintf(stderr, "ERROR : select() failed\n"));
  return (i);
}

int	xconnect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  int	i;

  if ((i = connect(sockfd, addr, addrlen)) < 0)
    close_and_exit(sockfd, "ERROR : connect() failed\n");
  return (i);
}

void    *xcalloc(size_t nmemb, size_t size)
{
  void  *ptr;

  if ((ptr = calloc(nmemb, size)) == NULL)
    exit(fprintf(stderr, "ERROR : calloc() failed\n"));
  return (ptr);
}

ssize_t		xwrite(int fd, const void *buf)
{
  ssize_t	i;

  if ((i = write(fd, buf, my_strlen((char *)buf))) < 0)
    exit(fprintf(stderr, "ERROR : write() failed"));
  return (i);
}
