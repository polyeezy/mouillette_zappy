##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_zappy
##
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
##
## Started on  Mon Jun 13 10:16:15 2016 Loïc Weinhard
## Last update Fri Jun 17 11:54:01 2016 Alexis Miele
## Last update Tue Jun 14 17:24:26 2016 Alexis Miele
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

SRV_OBJ		=	$(SRV_SRC:.c=.o)



CLT_NAME	=	zappy_ai

CLT_FOLDER	=	./src/client

CLT_SRC		=	$(CLT_FOLDER)/main.c		\
			$(CLT_FOLDER)/args.c		\
			$(CLT_FOLDER)/check_args.c	\
			$(CLT_FOLDER)/init.c		\

CLT_OBJ		=	$(CLT_SRC:.c=.o)



UTILS_FOLDER	=	./src/utils

UTILS_SRC	=	$(UTILS_FOLDER)/isitnum.c	\
			$(UTILS_FOLDER)/get_arg.c	\
			$(UTILS_FOLDER)/xfct_1.c	\
			$(UTILS_FOLDER)/xfct_2.c	\
			$(UTILS_FOLDER)/xfct_3.c	\

UTILS_OBJ	=	$(UTILS_SRC:.c=.o)



CFLAGS		+=	-Wall -Wextra -Werror -g
CFLAGS		+=	-Iinclude

MR_CLEAN        =       find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:	$(SRV_NAME) $(CLT_NAME)

$(SRV_NAME)	:	$(SRV_OBJ) $(UTILS_OBJ)
			gcc $(SRV_OBJ) $(UTILS_OBJ) -o $(SRV_NAME)

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
