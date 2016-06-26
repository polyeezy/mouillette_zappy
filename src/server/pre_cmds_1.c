/*
** pre_cmds.c for pre cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Sun Jun 26 13:17:21 2016 Alexis Miele
** Last update Sun Jun 26 21:12:45 2016 Alexis Miele
*/

#include "cmds.h"
#include "pile.h"
#include "xfct.h"

void	pre_avance(t_server *server, t_client *player,
		   char *buffer, t_cmd *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(buffer, " \n");
  if (lentab(tab) != 1)
    {
      xwrite(player->fd, "ko\n");
      free_tab(tab);
      return;
    }
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_droite(t_server *server, t_client *player,
		   char *buffer, t_cmd *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(buffer, " \n");
  if (lentab(tab) != 1)
    {
      xwrite(player->fd, "ko\n");
      free_tab(tab);
      return;
    }
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_gauche(t_server *server, t_client *player,
		   char *buffer, t_cmd *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(buffer, " \n");
  if (lentab(tab) != 1)
    {
      xwrite(player->fd, "ko\n");
      free_tab(tab);
      return;
    }
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_voir(t_server *server, t_client *player,
		 char *buffer, t_cmd *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(buffer, " \n");
  if (lentab(tab) != 1)
    {
      xwrite(player->fd, "ko\n");
      free_tab(tab);
      return;
    }
  add_pile(server, player, strdup(buffer), cmd);
}

void	pre_inventaire(t_server *server, t_client *player,
		       char *buffer, t_cmd *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(buffer, " \n");
  if (lentab(tab) != 1)
    {
      xwrite(player->fd, "ko\n");
      free_tab(tab);
      return;
    }
  add_pile(server, player, strdup(buffer), cmd);
}
