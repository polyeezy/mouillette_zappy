/*
** ai_cmd.h for ai_cmd in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Fri Jun 17 17:13:49 2016 Alexis Miele
** Last update Fri Jun 17 17:19:38 2016 Alexis Miele
*/

#ifndef		AI_CMD_H_
# define	AI_CMD_H_

void		ai_avance(t_client_socket *client, char *arg);
void		ai_droite(t_client_socket *client, char *arg);
void		ai_gauche(t_client_socket *client, char *arg);
void		ai_voir(t_client_socket *client, char *arg);
void		ai_inventaire(t_client_socket *client, char *arg);
void		ai_prend(t_client_socket *client, char *arg);
void		ai_pose(t_client_socket *client, char *arg);
void		ai_expulse(t_client_socket *client, char *arg);
void		ai_broadcast(t_client_socket *client, char *arg);
void		ai_incantation(t_client_socket *client, char *arg);
void		ai_fork(t_client_socket *client, char *arg);
void		ai_connect_nbr(t_client_socket *client, char *arg);
void		ai_dead(t_client_socket *client, char *arg);

#endif
