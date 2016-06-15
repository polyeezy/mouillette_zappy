/*
** socket_client.h for  in /home/polyeezy/rendu/CPP/mouillette_zappy/include
** 
** Made by Valérian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Tue Jun 14 06:26:09 2016 Valérian Polizzi
** Last update Tue Jun 14 06:27:49 2016 Valérian Polizzi
*/

#ifndef _SOCKET_CLIENT_H_
# define _SOCKET_CLIENT_H_

struct socket_client
{
  int			client_fd;
  int			server_fd;
  int			port;
  struct sockaddr_in	sock;
};

#endif
