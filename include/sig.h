/*
** signal.h for  in /home/weinha_l/Semestre_4/mouillette_zappy/include/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 14 13:52:12 2016 Loïc Weinhard
** Last update Tue Jun 14 13:54:51 2016 Loïc Weinhard
*/

#ifndef SIG_H_
# define SIG_H_

# include <signal.h>

char	g_exit;

void	handle_sigint(int signal);

#endif
