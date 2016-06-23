/*
** client_print.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 16:17:06 2016 Valerian Polizzi
** Last update Wed Jun 22 16:17:30 2016 Valerian Polizzi
*/

#include <client.h>

void            debug_material(t_materials *inv)
{
  printf("nourriture\t:%d\n",inv->food);
  printf("linemate\t:%d\n",inv->linemate);
  printf("deraumere\t:%d\n",inv->deraumere);
  printf("sibur\t\t:%d\n",inv->sibur);
  printf("mendiane\t:%d\n",inv->mendiane);
  printf("phiras\t\t:%d\n",inv->phiras);
  printf("thystame\t:%d\n",inv->thystame);
}
