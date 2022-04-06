##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile eval expr with libmy
##

SRC	=	main.c	\
		bsq.c	\
		tab.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

.PHONY : all clean fclean re

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -L lib/my/ -o $(NAME) -lmy
	rm -f *.o

clean:
	rm -f *.o
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	make clean -C lib/my
	rm -f ./a.out

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all
