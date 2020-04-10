##
## EPITECH PROJECT, 2020
## CPE_duostumper_4_2019
## File description:
## Makefile
##

LIB = lib/my/my_strlen.c	\

NAME = mixword

SRC = src/main.c	\
	src/words_in_grid.c	\

CFLAGS = -W -Wall -Wextra -lm -Iinclude -g3

OBJ = $(LIB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SRC) $(CLFAGS)

clean :
	rm -f *.o $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
