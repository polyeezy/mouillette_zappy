/*
** client_communication.c for  in /home/polizz_v/rendu/cPP/mouillette_zappy/src/client
** 
** Made by Valerian Polizzi
** Login   <polizz_v@epitech.net>
** 
** Started on  Wed Jun 22 15:54:18 2016 Valerian Polizzi
** Last update Wed Jun 22 15:55:58 2016 Valerian Polizzi
*/

#include <client.h>
#include <xfct.h>

int             send_cmd_server(t_ai *cli, char *msg)
{
  int          len;

  len = dprintf(cli->socket.fd, "%s\n", msg);
  return (len);
}

char            *get_server_response(t_ai *cli)
{
  char          buff[254];
  ssize_t       len;

  len = xread(cli->socket.fd, &buff, 255);
  buff[len] = 0;
  xfree(cli->last_response);
  cli->last_response = strdup(buff);
  return (cli->last_response);
}

char    *send_and_get(t_ai *cli, char *cmd)
{
  send_cmd_server(cli, cmd);
  get_server_response(cli);
  return (cli->last_response);
}
