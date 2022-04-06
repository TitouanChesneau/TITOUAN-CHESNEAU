/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** math
*/

#include "dante.h"
#include <time.h>

int get_distance(cell_t *start, cell_t *end)
{
    double res = (start->x - end->x) * (start->x - end->x) +
        (start->y - end->y) * (start->y - end->y);

    return (int)res;
}

bool contain_index(int *buffer, int size, int id)
{
    for (int i = 0; i < size; i++)
        if (buffer[i] == id)
            return 1;
    return 0;
}

cell_t *clean_cell(maze_t *map, cell_t **cell,
cell_t *end, cell_t *current)
{
    int *buffer = NULL;
    int index = 0;
    int cell_size = 4;
    int dist = 2147483647;
    cell_t *nearest = NULL;
    int len = 0;

    buffer = malloc(sizeof(int) * map->real_len);
    for (int i = 0; i < cell_size; i++, len++) {
        if (cell[i] == NULL || cell[i]->state != EMPTY ||
        !(cell[i]->id >= 0 && cell[i]->id <= map->real_len - 1)
        || contain_index(buffer, index, cell[i]->id))
            continue;
        if (cell[i]->end == 1)
            return cell[i];
        if (get_distance(cell[i], end) < dist ||
            (get_distance(cell[i], end) <= dist
            && rand() % 2 == 1)) {
            dist = get_distance(cell[i], end);
            nearest = cell[i];
        }
    }
    if (len > 1) {
        buffer[index] = current->id;
        index++;
    }
    return nearest;
}
