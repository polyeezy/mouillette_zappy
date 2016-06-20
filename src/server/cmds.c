/*
** cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:26:12 2016 Loïc Weinhard
** Last update Sat Jun 18 16:45:04 2016 Loïc Weinhard
*/

#include "cmds.h"

t_cmd	g_cmds[NUMBER_OF_COMMANDS] =
{
    {
      "droite",
      "droite : tourne le personnage vers la droite",
      &droite
    },
    {
      "gauche",
      "gauche : tourne le personnage vers la gauche",
      &gauche
    }
};
