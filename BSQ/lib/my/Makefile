##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile to create lib & copy my.h & lib
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_is_num_char.c	\
		str_to_word_array.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all:    $(NAME)

$(NAME):        $(OBJ)

	ar rc $(NAME) *.o
	rm -f *.o

clean:
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:     fclean all
