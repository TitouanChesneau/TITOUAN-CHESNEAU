##
## EPITECH PROJECT, 2022
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
		my_showmem.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_arrlen.c 	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_is_num_char.c	\
		my_int_to_str.c		\
		my_verify_str.c		\
		my_memset.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_nt.c	\
		my_str_to_word_array_lj.c	\
		my_strconcat.c	\
		my_count_column.c	\
		my_arrdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

test: $(OBJ)
	ar rc libmy.a $(OBJ)
	$(RM) $(OBJ)

clean:
	rm -f $(OBJ) $(NAME) *~
	rm -f libmy.a
