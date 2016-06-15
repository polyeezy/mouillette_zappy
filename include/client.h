/*
** client.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Mon Jun 13 11:11:15 2016 Loïc Weinhard
<<<<<<< HEAD
** Last update Tue Jun 14 05:48:26 2016 Valérian Polizzi
=======
** Last update Tue Jun 14 16:07:32 2016 Loïc Weinhard
>>>>>>> 1f8c83415df552f0bd0cec09bc316f21332e1cb5
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "orientation.h"
# include "materials.h"
# include <stdio.h>
# include <string.h>

typedef struct		s_client
{
  int			fd;
  char			*team;
  int			x;
  int			y;
  t_orientation		orientation;
  t_materials		materials;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

void	free_clients(t_client *clients);
int	client_check_params(int, char **);
void	client_init(t_client**, char *team, char *port, char *host);

#endif
