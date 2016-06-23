/*
** ai_cmd_1.c for ai cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:02:23 2016 Alexis Miele
** Last update Wed Jun 22 16:43:05 2016 Valerian Polizzi
*/

#include "client.h"

void	ai_avance(t_ai *cli)
{
  send_and_get(cli, "avance");
}

void	ai_droite(t_ai *cli)
{
  send_and_get(cli, "droite");
}

void	ai_gauche(t_ai *cli)
{
  send_and_get(cli, "gauche");
}

void	ai_voir(t_ai *cli)
{
  send_and_get(cli, "voir");
}

void	ai_inventaire(t_ai *cli)
{
  send_and_get(cli, "inventaire");
}
