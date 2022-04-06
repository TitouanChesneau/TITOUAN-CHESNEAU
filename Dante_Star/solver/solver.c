/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** engine
*/

#include "dante.h"

void process(maze_t *map)
{
    cell_t *start = map->cells[0];
    cell_t *end =  map->cells[map->real_len - 1];
    int call = 0;

    if (start == NULL || end == NULL)
        return;
    if (end->state != EMPTY || start->state != EMPTY) {
        my_putstr("no solution found\n");
        return;
    }
    for (int i = 0; i < map->map_width * map->map_height * 4; i++) {
        clear_map(map);
        call = find_path(map, start, end);
        if (call == 0 && i + 1 >=
            map->map_width * map->map_height * 4) {
            my_putstr("no solution found\n");
            return;
        } else if (call == 1)
            break;
    }
    compute_result(map);
}

int find_path(maze_t *map, cell_t *start, cell_t *end)
{
    cell_t *current = start;
    int turn = 0;

    start->state = USED;
    while (current->end != true) {
        current = find_nearest(map, current, end);
        if (current == NULL || turn > map->cells_len)
            break;
        current->state = USED;
        if (current->end == true)
            return 1;
        turn++;
    }
    return 0;
}

cell_t *find_nearest(maze_t *map, cell_t *current,
cell_t *end)
{
    int cell_size = 4;
    cell_t **cell = malloc(sizeof(cell_t *) * cell_size);
    cell_t *nearest = NULL;

    if (current->id + 1 <= map->real_len - 1 &&
        current->y == map->cells[current->id + 1]->y)
        cell[0] = get_cell_by_id(map, current->id + 1);
    else
        cell[0] = NULL;
    if (current->id - 1 >= 0 &&
        current->y == map->cells[current->id - 1]->y)
        cell[1] = get_cell_by_id(map, current->id - 1);
    else
        cell[1] = NULL;
    cell[2] = get_cell_by_id(map, current->id + map->map_width + 1);
    cell[3] = get_cell_by_id(map, current->id - (map->map_width + 1));
    nearest = clean_cell(map, cell, end, current);
    free(cell);
    return nearest;
}

void compute_result(maze_t *map)
{
    char *result = malloc(sizeof(char) * (map->real_len + 2));
    int i = 0;
    char cells_stock[3] = { '*', 'X', 'o' };

    for (; i < map->real_len && map->cells[i]; i++) {
        if (map->cells[i]->state < 0)
            result[i] = '\n';
        else
            result[i] = cells_stock[map->cells[i]->state];
	}
    result[i++] = '\0';
    write(1, result, map->real_len + 2);
    free(result);
}
