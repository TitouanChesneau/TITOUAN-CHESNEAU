/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct square {
    int size_big;
    int x_big;
    int y_big;
} square_t;

char **malloc_tab(char const *str);

void buff_to_str(char *str);

int error_handler(char *str);

int fs_open_file(char const *file_path);

void squaring_map(char **tab, int x, int y);

void first_line(char **tab);

void display_tab(char **tab);

void find_biggest(square_t square, char **tab);

void find_the_square(char **tab);

void display_map(char **fullbuff);

#endif /* BSQ_H_ */