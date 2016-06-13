##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_zappy
##
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
##
## Started on  Mon Jun 13 10:16:15 2016 Loïc Weinhard
## Last update Mon Jun 13 15:33:19 2016 Loïc Weinhard
##

SRV_NAME	=	zappy_server

SRV_FOLDER	=	./src/server

SRV_SRC		=	$(SRV_FOLDER)/main.c		\
			$(SRV_FOLDER)/args.c		\
			$(SRV_FOLDER)/check_args.c	\

SRV_OBJ		=	$(SRV_SRC:.c=.o)



CLT_NAME	=	zappy_ai

CLT_FOLDER	=	./src/client

CLT_SRC		=	$(CLT_FOLDER)/main.c		\

CLT_OBJ		=	$(CLT_SRC:.c=.o)



UTILS_FOLDER	=	./src/utils

UTILS_SRC	=	$(UTILS_FOLDER)/isitnum.c	\

UTILS_OBJ	=	$(UTILS_SRC:.c=.o)



CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-Iinclude



all		:	$(SRV_NAME) $(CLT_NAME)

$(SRV_NAME)	:	$(SRV_OBJ) $(UTILS_OBJ)
			gcc $(SRV_OBJ) $(UTILS_OBJ) -o $(SRV_NAME)

$(CLT_NAME)	:	$(CLT_OBJ) $(UTILS_OBJ)
			gcc $(CLT_OBJ) $(UTILS_OBJ) -o $(CLT_NAME)

clean		:
			rm -rf $(SRV_OBJ)
			rm -rf $(CLT_OBJ)
			rm -rf $(UTILS_OBJ)

fclean		:	clean
			rm -rf $(SRV_NAME)
			rm -rf $(CLT_NAME)

re		:	fclean all

.PHONY		:	all re clean fclean
