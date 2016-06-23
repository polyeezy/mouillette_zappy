##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_zappy
##
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
##
## Started on  Mon Jun 13 10:16:15 2016 Loïc Weinhard
## Last update Thu Jun 23 16:59:27 2016 Loïc Weinhard
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

CLT_SRC		=	$(CLT_FOLDER)/args.c			\
			$(CLT_FOLDER)/check_args.c		\
			$(CLT_FOLDER)/init.c			\
			$(CLT_FOLDER)/client_communication.c	\
			$(CLT_FOLDER)/client_objects.c		\
			$(CLT_FOLDER)/client_print.c		\
			$(CLT_FOLDER)/client_vision.c		\
			$(CLT_FOLDER)/client_movement.c		\
			$(CLT_FOLDER)/ai_cmd_1.c		\
			$(CLT_FOLDER)/ai_cmd_2.c		\
			$(CLT_FOLDER)/client_get_lvl1.c		\
			$(CLT_FOLDER)/main.c			\


CLT_OBJ		=	$(CLT_SRC:.c=.o)

GFX_NAME	=	zappy_gfx

GFX_FOLDER	=	./src/gfx

GFX_SRC		=	$(GFX_FOLDER)/draw.c			\
			$(GFX_FOLDER)/free.c			\
			$(GFX_FOLDER)/graphics.c		\
			$(GFX_FOLDER)/info.c			\
			$(GFX_FOLDER)/init.c			\
			$(GFX_FOLDER)/init_info.c		\
			$(GFX_FOLDER)/input.c			\
			$(GFX_FOLDER)/main.c			\
			$(GFX_FOLDER)/client_communication.c	\
			$(GFX_FOLDER)/init_client.c		\
			$(GFX_FOLDER)/mapi.c			\
			$(GFX_FOLDER)/args.c			\

GFX_OBJ		=	$(GFX_SRC:.c=.o)


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
			$(UTILS_FOLDER)/itoa.c			\

UTILS_OBJ	=	$(UTILS_SRC:.c=.o)



CFLAGS		+=	-Wall -Wextra -Werror -g
CFLAGS		+=	-Iinclude
LFLAGS		=	`sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf

MR_CLEAN        =       find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:	$(SRV_NAME) $(CLT_NAME) $(GFX_NAME)

$(SRV_NAME)	:	$(SRV_OBJ) $(UTILS_OBJ)
			gcc $(SRV_OBJ) $(UTILS_OBJ) -o $(SRV_NAME) -g3

$(CLT_NAME)	:	$(CLT_OBJ) $(UTILS_OBJ)
			gcc $(CLT_OBJ) $(UTILS_OBJ) -o $(CLT_NAME)

$(GFX_NAME)	:	$(GFX_OBJ) $(UTILS_OBJ) 
			gcc $(LFLAGS) $(GFX_OBJ) $(UTILS_OBJ) -o $(GFX_NAME)


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
