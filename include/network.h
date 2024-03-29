/*
** network.h for  in /home/weinha_l/Semestre_4/PSU_2015_myftp/include
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.net>
**
** Started on  Mon May  2 17:09:26 2016 Loïc Weinhard
** Last update Sun Jun 26 21:23:31 2016 Aurelie Orset
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define DOMAIN		AF_INET
# define TYPE		SOCK_STREAM
# define PROTOCOL	"TCP"
# define ADDRESSES	INADDR_ANY
# define QUEUE		42

#endif
