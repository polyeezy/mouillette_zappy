##
## Makefile for zappy in /home/oreo/Downloads/tutorial_11
## 
## Made by Aurelie Orset
## Login   <orset_a@epitech.net>
## 
## Started on  Fri Jun 17 15:49:16 2016 Aurelie Orset
## Last update Thu Jun 23 13:17:04 2016 Aurelie Orset
##

SRC	=	src/draw.c\
		src/init.c\
	 	src/input.c\
		src/graphics.c\
		src/main.c\
		src/mapi.c\
		src/free.c\
		src/init_info.c\
		src/info.c

OBJ	= $(SRC:.c=.o)
NAME	= zappy
CC	= gcc
CFLAGS	= -W -Wextra -ansi -Wall -pedantic -Werror -I./include -g3 
LFLAGS	= `sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	rm -rf $(NAME) 

fclean: clean
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean re
