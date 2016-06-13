/*
** xfct_2.c for  in /home/weinha_l/Semestre_4/PSU_2015_myftp/src
** 
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
** 
** Started on  Mon May  2 18:11:07 2016 Loïc Weinhard
** Last update Mon May  2 19:12:47 2016 Loïc Weinhard
*/

#include "xfct.h"

static void	close_and_exit(int sockfd, char *msg)
{
  xclose(sockfd);
  fprintf(stderr, msg);
  exit(EXIT_FAILURE);
}

void	xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    close_and_exit(sockfd, "ERROR : bind() failed\n");
}

void	xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    close_and_exit(sockfd, "ERROR : listen() failed\n");
}

int	xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int	fd;

  if ((fd = accept(sockfd, addr, addrlen)) == -1)
    close_and_exit(sockfd, "ERROR : accept() failed\n");
  return (fd);
}

int	xhtons(int sockfd, int port)
{
  int	final;

  if ((final = htons(port)) == -1)
    close_and_exit(sockfd, "ERROR : htons() failed\n");
  return (final);
}
