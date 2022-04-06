##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for solver
##

SRC	=	main.c	\
		solver.c	\
		checks.c	\
		open_file.c	\
		maze.c	\
		path.c	\

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib/my/ -lmy

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iincludes/

CCRITERION	= 	--coverage -lcriterion

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	make -C ../lib/my/
	$(CC) -o unit_tests $(FILES) $(TESTS) $(CFLAGS) $(CPPFLAGS) $(CCRITERION)
	./unit_tests

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C ../lib/my
	$(RM) $(NAME)
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda

re: fclean all

.PHONY : all re clean tests_run fclean
