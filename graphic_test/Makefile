##
## Makefile for zappy in /home/oreo/Downloads/tutorial_11
## 
## Made by Aurelie Orset
## Login   <orset_a@epitech.net>
## 
## Started on  Fri Jun 17 15:49:16 2016 Aurelie Orset
## Last update Tue Jun 21 17:45:32 2016 Aurelie Orset
##

SRC	=	src/draw.c\
		src/init.c\
	 	src/input.c\
		src/graphics.c\
		src/main.c\
		src/map.c

OBJ	= $(SRC:.c=.o)
NAME	= zappy
CC	= gcc
CFLAGS	= -Wall -pedantic -Werror -I./include -g3 
LFLAGS	= `sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	rm -rf $(NAME) 

fclean: clean
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean re
