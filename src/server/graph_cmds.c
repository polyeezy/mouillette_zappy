/*
** graph_cmds.c for  in /home/weinha_l/Semestre_4/mouillette_zappy/src/server/
**
** Made by Loïc Weinhard
** Login   <weinha_l@epitech.eu>
**
** Started on  Sun Jun 26 11:20:42 2016 Loïc Weinhard
** Last update Sun Jun 26 13:12:07 2016 Loïc Weinhard
*/

#include "graphic_client.h"

t_graph_cmd	g_graph_cmds[NUMBER_OF_GRAPH_COMMANDS] = {
    {
      "bct",
      "bct : donne l'information sur la case",
      &bct
    },
    {
      "lpy",
      "lpy : liste les joueurs sur la carte",
      &lpy
    },
    {
      "plv",
      "plv : donne le niveau du joueur",
      &plv
    }
};
