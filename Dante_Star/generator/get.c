/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** functions used to get stuff
*/

#include <stdlib.h>
#include "dante.h"
#include "my.h"

int randint(int max)
{
    return (rand() % max);
}

direction get_diag_direction(int x)
{
    if (x == 0)
        return right_up;
    if (x == 1)
        return right_down;
    if (x == 2)
        return left_up;
    if (x == 3)
        return left_down;
    return unknown;
}

direction get_direction(int x)
{
    if (x == 0)
        return up;
    if (x == 1)
        return right;
    if (x == 2)
        return left;
    if (x == 3)
        return down;
    return unknown;
}

vector2i get_vector(int x, int y)
{
    vector2i vector = {x, y};

    return vector;
}
