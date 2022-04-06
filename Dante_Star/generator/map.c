/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** functions related to making the map
*/

#include <time.h>
#include <stdlib.h>
#include "dante.h"

char **init_map(int x, int y, char c)
{
    int i;
    int k;
    char **map = malloc((y + 1) * sizeof(char *));

    for (i = 0; i < y; ++i)
        map[i] = malloc ((x + 1) * sizeof(char));
    map[i] = NULL;
    for (int j = 0; j < y; ++j) {
        for (k = 0; k < x; ++k) {
            map[j][k] = c;
        }
        map[j][x] = '\0';
    }
    map[0][0] = '*';
    map[y - 1][x - 1] = '*';
    return map;
}

int nb_x_proximity(char **map, vector2i pos, vector2i dimensions)
{
    int count = 0;

    if (pos.y > 0 && map[pos.y - 1][pos.x] == 'X')
        ++count;
    if (pos.y < (dimensions.y - 1) && map[pos.y + 1][pos.x] == 'X')
        ++count;
    if (pos.x > 0 && map[pos.y][pos.x - 1] == 'X')
        ++count;
    if (pos.x < (dimensions.x - 1) && map[pos.y][pos.x + 1] == 'X')
        ++count;
    if (pos.x > (dimensions.x - 2) || pos.y > (dimensions.y - 2))
        return 2;
    return count;
}

static vector2i move_pos(vector2i old_pos,
direction direc, vector2i dimensions)
{
    vector2i pos = {old_pos.x, old_pos.y};
    int width = dimensions.x;
    int length = dimensions.y;

    if (direc == right && pos.x < (width - 1))
        pos.x += 1;
    if (direc == left && pos.x > 0)
        pos.x -= 1;
    if (direc == up && pos.y > 0)
        pos.y -= 1;
    if (direc == down && pos.y < (length - 1))
        pos.y += 1;
    return pos;
}

void make_path(char **map, int width, int length)
{
    int nb = 2;
    vector2i pos = {0, 0};
    vector2i dimensions = {width, length};
    vector2i old_pos;

    srand(time(NULL));
    while (pos.x != (width - 1) || pos.y != (length - 1)) {
        old_pos = pos;
        pos = move_pos(pos, get_direction(randint(4)), dimensions);
        if (nb_x_proximity(map, pos, dimensions) >= nb) {
            nb = 2;
            map[pos.y][pos.x] = '*';
        } else {
            pos = old_pos;
            nb = 0;
        }
    }
}
