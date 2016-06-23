##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_zappy
##
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
##
## Started on  Mon Jun 13 10:16:15 2016 Loïc Weinhard
## Last update Thu Jun 23 14:47:08 2016 Loïc Weinhard
##

SRV_NAME	=	zappy_server

SRV_FOLDER	=	./src/server

SRV_SRC		=	$(SRV_FOLDER)/main.c		\
			$(SRV_FOLDER)/args.c		\
			$(SRV_FOLDER)/check_args.c	\
			$(SRV_FOLDER)/init.c		\
			$(SRV_FOLDER)/close.c		\
			$(SRV_FOLDER)/teams.c		\
			$(SRV_FOLDER)/clients.c		\
			$(SRV_FOLDER)/signal.c		\
			$(SRV_FOLDER)/accept_client.c	\
			$(SRV_FOLDER)/handle_cmds.c	\
			$(SRV_FOLDER)/droite.c		\
			$(SRV_FOLDER)/cmds.c		\
			$(SRV_FOLDER)/gauche.c		\
			$(SRV_FOLDER)/voir.c		\
			$(SRV_FOLDER)/modulo.c		\
			$(SRV_FOLDER)/get_elems.c	\
			$(SRV_FOLDER)/inventaire.c	\
			$(SRV_FOLDER)/avance.c		\
			$(SRV_FOLDER)/relink.c		\
			$(SRV_FOLDER)/check_syntax.c	\
			$(SRV_FOLDER)/prend.c		\
			$(SRV_FOLDER)/pose.c		\
			$(SRV_FOLDER)/levels.c		\
			$(SRV_FOLDER)/incantation.c	\
			$(SRV_FOLDER)/broadcast.c	\

SRV_OBJ		=	$(SRV_SRC:.c=.o)



CLT_NAME	=	zappy_ai

CLT_FOLDER	=	./src/client

CLT_SRC		=	$(CLT_FOLDER)/main.c		\
			$(CLT_FOLDER)/args.c		\
			$(CLT_FOLDER)/check_args.c	\
			$(CLT_FOLDER)/init.c		\
			$(CLT_FOLDER)/ai_cmd_1.c	\
			$(CLT_FOLDER)/ai_cmd_2.c	\
			$(CLT_FOLDER)/ai_cmd_3.c	\

CLT_OBJ		=	$(CLT_SRC:.c=.o)



UTILS_FOLDER	=	./src/utils

UTILS_SRC	=	$(UTILS_FOLDER)/isitnum.c		\
			$(UTILS_FOLDER)/get_arg.c		\
			$(UTILS_FOLDER)/xfct_1.c		\
			$(UTILS_FOLDER)/xfct_2.c		\
			$(UTILS_FOLDER)/xfct_3.c		\
			$(UTILS_FOLDER)/my_str_to_wordtab.c	\
			$(UTILS_FOLDER)/free_tab.c		\
			$(UTILS_FOLDER)/my_strcat.c		\
			$(UTILS_FOLDER)/lentab.c		\
			$(UTILS_FOLDER)/my_strlen.c		\

UTILS_OBJ	=	$(UTILS_SRC:.c=.o)



CFLAGS		+=	-Wall -Wextra -Werror -g
CFLAGS		+=	-Iinclude

MR_CLEAN        =       find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:	$(SRV_NAME) $(CLT_NAME)

$(SRV_NAME)	:	$(SRV_OBJ) $(UTILS_OBJ)
			gcc $(SRV_OBJ) $(UTILS_OBJ) -o $(SRV_NAME) -g3

$(CLT_NAME)	:	$(CLT_OBJ) $(UTILS_OBJ)
			gcc $(CLT_OBJ) $(UTILS_OBJ) -o $(CLT_NAME)

clean		:
			$(MR_CLEAN)
			rm -rf $(SRV_OBJ)
			rm -rf $(CLT_OBJ)
			rm -rf $(UTILS_OBJ)

fclean		:	clean
			rm -rf $(SRV_NAME)
			rm -rf $(CLT_NAME)

re		:	fclean all

.PHONY		:	all re clean fclean
