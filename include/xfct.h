/*
** xfct.h for  in /home/weinha_l/Semestre_4/PSU_2015_myftp/include
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
**
** Started on  Mon May  2 16:32:32 2016 Loïc Weinhard
** Last update Sun Jun 26 21:24:11 2016 Aurelie Orset
*/

#ifndef XFCT_H_
# define XFCT_H_

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <unistd.h>
# include <netdb.h>
# include "server.h"

void		close_and_exit(int sockfd, char *msg);
void		*xmalloc(size_t size);
void		xfree(void *ptr);
void		xclose(int fd);
int		xgetprotobyname(const char *name);
int		xsocket(int domain, int type, int protocol);

void		xbind(int sockfd, const struct sockaddr *addr,
			socklen_t addrlen);
void		xlisten(int sockfd, int backlog);
int		xaccept(int sockfd, struct sockaddr *addr,
			  socklen_t *addrlen);
int		xhtons(int sockfd, int port);

ssize_t		xread(int fd, void *buf, size_t count);
int		xselect(int nfds, fd_set *read, fd_set *write,
			  fd_set *except, struct timeval *time);
int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen);
void		*xcalloc(size_t nmemb, size_t size);
ssize_t		xwrite(int fd, const void *buf);
char		*xstrdup(const char *s);

#endif
