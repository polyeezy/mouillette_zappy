/*
** cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:26:12 2016 Loïc Weinhard
** Last update Wed Jun 22 15:54:56 2016 Loïc Weinhard
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
    },
    {
      "voir",
      "voir : dévoile le contenu des cases alentours",
      &voir
    },
    {
      "inventaire",
      "inventaire : dévoile le contenu de l'inventaire",
      &inventaire
    },
    {
      "avance",
      "avance : avance le personnage d'une case",
      &avance
    },
    {
      "prend",
      "prend objet : prend l'objet sur la case",
      &prend
    },
    {
      "pose",
      "pose objet : pose l'objet sur la case",
      &pose
    },
    {
      "incantation",
      "incantation : augmente le niveau du personnage",
      &incantation
    }
};
