##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for generator
##

SRC	=	main.c	\
		error_handling.c	\
		generator.c	\
		map.c	\
		get.c	\
		perfect_map.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib/my/ -lmy

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iincludes/

CCRITERION	= 	--coverage -lcriterion

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	make -C ../lib/my/
	$(CC) -o unit_tests $(FILES) $(TESTS) $(CFLAGS) $(CPPFLAGS) $(CCRITERION)
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C ../lib/my
	$(RM) $(NAME)
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda

re: fclean all

.PHONY : all re clean tests_run fclean
