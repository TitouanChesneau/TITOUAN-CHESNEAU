/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** generator for dante_star
*/

#include <stdio.h>
#include "dante.h"

void perfect_generator(int x, int y)
{
    int i;
    char **map = init_map(x, y, 'X');

    make_perfect_path(map, x, y);
    for (i = 0; i < (y - 1); ++i) {
        printf("%s\n", map[i]);
    }
    printf("%s", map[i]);
}

void generator(int x, int y)
{
    int i;
    char **map = init_map(x, y, 'X');

    make_path(map, x, y);
    for (i = 0; i < (y - 1); ++i) {
        printf("%s\n", map[i]);
    }
    printf("%s", map[i]);
}
