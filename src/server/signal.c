/*
** signal.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Tue Jun 14 13:48:57 2016 Loïc Weinhard
** Last update Sun Jun 26 15:32:52 2016 Loïc Weinhard
*/

#include <signal.h>
#include "sig.h"

extern char g_exit;

void	handle_sigint(int signal)
{
  (void)signal;
  g_exit = 1;
}
