/*
** EPITECH PROJECT, 2022
** perfect_map.c
** File description:
** functions that are used to create the perfect map
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dante.h"

static vector2i fill_rand(char **map, vector2i dimensions,
vector2i index, direction dir)
{
    if (dir == right && index.x < (dimensions.x - 1)) {
        map[index.y][index.x + 1] = '*';
        index.x += 1;
    }
    if (dir == down && index.y < (dimensions.y - 1)) {
        map[index.y + 1][index.x] = '*';
        index.y += 1;
    }
    return index;
}

void make_perfect_path(char **map, int width, int length)
{
    vector2i pos = {0, 0};
    vector2i dimensions = {width, length};

    srand(time(NULL));
    while (pos.x != (width - 1) || pos.y != (length - 1)) {
        pos = fill_rand(map, dimensions, pos,
        get_direction(randint(4)));
    }
}
