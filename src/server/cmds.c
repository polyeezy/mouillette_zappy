/*
** cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sat Jun 18 16:26:12 2016 Loïc Weinhard
** Last update Sun Jun 26 14:53:01 2016 Alexis Miele
*/

#include "cmds.h"

t_cmd	g_cmds[NUMBER_OF_COMMANDS] =
{
    {
      "droite",
      "droite : tourne le personnage vers la droite",
      7,
      &pre_droite,
      &droite
    },
    {
      "gauche",
      "gauche : tourne le personnage vers la gauche",
      7,
      &pre_gauche,
      &gauche
    },
    {
      "voir",
      "voir : dévoile le contenu des cases alentours",
      7,
      &pre_voir,
      &voir
    },
    {
      "inventaire",
      "inventaire : dévoile le contenu de l'inventaire",
      1,
      &pre_inventaire,
      &inventaire
    },
    {
      "avance",
      "avance : avance le personnage d'une case",
      7,
      &pre_avance,
      &avance
    },
    {
      "prend",
      "prend objet : prend l'objet sur la case",
      7,
      &pre_prend,
      &prend
    },
    {
      "pose",
      "pose objet : pose l'objet sur la case",
      7,
      &pre_pose,
      &pose
    },
    {
      "incantation",
      "incantation : augmente le niveau du personnage",
      300,
      &pre_incantation,
      &incantation
    },
    {
      "broadcast",
      "broadcast message : envoie un message à tous les joueurs",
      7,
      &pre_broadcast,
      &broadcast
    },
    {
      "connect_nbr",
      "connect_nbr : nombre de slots non utilisés par l'équipe",
      0,
      &pre_connect_nbr,
      &connect_nbr
    },
    {
      "mange",
      "mange : Enlève une unité de temps",
      126,
      &pre_mange,
      &mange
    }
};
