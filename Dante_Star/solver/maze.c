/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** map
*/

#include "dante.h"

int get_map_width(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            return (i);
    return 0;
}

int get_map_height(char *str)
{
    return (len_char(str, '\n') + 2);
}

void clear_map(maze_t *map)
{
    cell_t *start = map->cells[0];
    cell_t *end =  map->cells[map->real_len - 1];

    start->start = 1;
    end->end = 1;
    for (int i = 0; i < map->real_len; i++)
        if (map->cells[i]->state == USED)
            map->cells[i]->state = EMPTY;
}

cell_t *get_cell_by_id(maze_t *map, int id)
{
    if (id >= 0 && id < map->real_len)
        return (map->cells[id]);
    return NULL;
}

int get_state(char c)
{
    const int state_len = 3;
    char cells_value[3] = { '*', 'X', 'o' };

    for (int i = 0; i < state_len; i++)
        if (cells_value[i] == c)
            return (i);
    return -1;
}
