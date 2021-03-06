/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** new1
*/

#include "include/bsq.h"

void squaring_map(char **tab, int x, int y)
{
    int up = tab[y - 1][x];
    int up_left = tab[y - 1][x - 1];
    int left = tab[y][x - 1];

    if (up <= up_left && up <= left)
        tab[y][x] = up + 1;
    if (up_left <= up && up_left <= left)
        tab[y][x] = up_left + 1;
    if (left <= up_left && left <= up)
        tab[y][x] = left + 1;
}

void first_line(char **tab)
{
    int x = 0;
    int y = 0;

    for (x = 0; tab[0][x] != '\0'; x++) {
        if (tab[0][x] == 'o')
            tab[0][x] = 1;
        else
            tab[0][x] = 2;
    }
    for (y = 0; tab[y] != 0; y++) {
        if (tab[y][0] == 'o' || tab[y][0] == 1)
            tab[y][0] = 1;
        else
            tab[y][0] = 2;
    }
}

void display_tab(char **tab)
{
    int x = 0;
    int y = 0;

    for (y; tab[y] != 0; y++)
        for (x = 0; tab[y][x] != '\0'; x++)
            if (tab[y][x] == 1)
                tab[y][x] = 'o';
            else if (tab[y][x] != 'x')
                tab[y][x] = '.';
    display_map(tab);
}

void find_biggest(square_t square, char **tab)
{
    int y = 0;
    int x = 0;
    int big = 0;
    int y_big = 0;
    int x_big = 0;

    for (y; tab[y] != 0; y++)
        for (x = 0; tab[y][x] != '\0'; x++)
            if (square.size_big < tab[y][x]) {
                square.size_big = tab[y][x];
                square.x_big = x;
                square.y_big = y;
            }
    big = square.size_big - 2;
    y_big = square.y_big;
    x_big = square.x_big;
    for (y = y_big - big; y <= y_big; y++)
        for (x = x_big - big; x <= x_big; x++)
            tab[y][x] = 'x';
    display_tab(tab);
}

void find_the_square(char **tab)
{
    int y = 1;
    int x = 1;
    square_t square = {1, 0, 0};

    first_line(tab);
    for (y = 1; tab[y] != 0; y++)
        for (x = 1; tab[y][x] != '\0'; x++)
            if (tab[y][x] == 'o')
                tab[y][x] = 1;
            else
                squaring_map(tab, x, y);
    find_biggest(square, tab);
    for (y = 0; tab[y] != 0; y++)
        free(tab[y]);
    free(tab);
}