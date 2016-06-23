/*
** client_communication.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 15:54:18 2016 Valerian Polizzi
** Last update Thu Jun 23 18:49:17 2016 Aurelie Orset
*/

#include <client.h>
#include <xfct.h>

int             send_cmd_server_gfx(t_client_socket *cli, char *msg)
{
  int          len;

  len = dprintf(cli->fd, "%s\n", msg);
  return (len);
}

char            *get_server_response_gfx(t_client_socket *cli)
{
  char          *buff;
  ssize_t       len;

  buff = malloc(sizeof(char) * 256);
  len = xread(cli->fd, buff, 255);
  if (len > 0)
    buff[len] = 0;
  return (buff);
}

char    *send_and_get_gfx(t_client_socket *cli, char *cmd)
{
  send_cmd_server_gfx(cli, cmd);
  return (get_server_response_gfx(cli));
}
