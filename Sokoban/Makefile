##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for project
##

SRC	=	main.c \
		src/sokoban.c \
		src/display.c \
		src/map_handeling.c \
		src/checks.c \
		src/checks2.c \
		src/free.c \
		src/move.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincludes -lncurses -L lib/my/ -lmy

CCRITERION	= 	--coverage -lcriterion

COMPIL	=	gcc

NAME = my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(COMPIL) -o $(NAME) $(OBJ) -g $(CFLAGS)
	rm -f src/*.o
	rm -f *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all re clean fclean
