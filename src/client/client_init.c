/*
** client_init.c for  in /home/polyeezy/rendu/CPP/mouillette_zappy/src/client
** 
** Made by Valérian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Tue Jun 14 05:40:36 2016 Valérian Polizzi
** Last update Wed Jun 15 02:40:06 2016 Valérian Polizzi
*/

#include <client.h>

void		client_init(t_client **client, char *team, char *port, char *host)
{
  (*client)->team = team;
  (void)port;
  (void)host;
}
