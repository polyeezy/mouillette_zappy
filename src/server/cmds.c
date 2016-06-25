/*
** cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:26:12 2016 Loïc Weinhard
** Last update Fri Jun 24 14:24:41 2016 Loïc Weinhard
*/

#include "cmds.h"

t_cmd	g_cmds[NUMBER_OF_COMMANDS] =
{
    {
      "droite",
      "droite : tourne le personnage vers la droite",
      7,
      &droite
    },
    {
      "gauche",
      "gauche : tourne le personnage vers la gauche",
      7,
      &gauche
    },
    {
      "voir",
      "voir : dévoile le contenu des cases alentours",
      7,
      &voir
    },
    {
      "inventaire",
      "inventaire : dévoile le contenu de l'inventaire",
      1,
      &inventaire
    },
    {
      "avance",
      "avance : avance le personnage d'une case",
      7,
      &avance
    },
    {
      "prend",
      "prend objet : prend l'objet sur la case",
      7,
      &prend
    },
    {
      "pose",
      "pose objet : pose l'objet sur la case",
      7,
      &pose
    },
    {
      "incantation",
      "incantation : augmente le niveau du personnage",
      300,
      &incantation
    },
    {
      "broadcast",
      "broadcast message : envoie un message à tous les joueurs",
      7,
      &broadcast
    }
};
