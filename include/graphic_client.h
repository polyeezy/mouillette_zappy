/*
** graphic_client.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 10:20:08 2016 Loïc Weinhard
** Last update Sun Jun 26 10:52:35 2016 Loïc Weinhard
*/

#ifndef GRAPHIC_CLIENT_H_
# define GRAPHIC_CLIENT_H_

# include "server.h"

typedef struct s_server t_server;

typedef struct		s_graphic
{
  int			fd;
  struct s_graphic	*next;
}			t_graphic;

void	add_graphic(t_server *server, t_graphic **graphic, int new_fd);

#endif
