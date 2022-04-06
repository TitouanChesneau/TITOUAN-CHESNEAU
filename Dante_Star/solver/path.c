/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** maze
*/

#include "dante.h"

maze_t *get_maze(char *file_name)
{
	maze_t *map = malloc(sizeof(maze_t));
	char *content = read_file(file_name);

	map->map_width = get_map_width(content);
	map->map_height = get_map_height(content);
	map->cells_len = map->map_width * map->map_height;
	map->real_len = 0;
	if (map->cells_len == 0)
		return NULL;
	map->cells = malloc(sizeof(struct cell*) * map->cells_len);
	if (check_maze(map, content) == false)
		return NULL;
	free(content);
	return map;
}

cell_t *get_cell(int id, int x, int y, int state)
{
	cell_t *cell = malloc(sizeof(cell_t));

	cell->id = id;
	cell->x = x;
	cell->y = y;
	cell->state = state;
	cell->start = false;
	cell->end = false;
	return cell;
}

int check_maze(maze_t *map, char *content)
{
	int x = 0;
	int y = 0;

	for (int i = 0; content[i] && i < map->cells_len; i++) {
		map->cells[i] = get_cell(i, x, y, get_state(content[i]));
		if (map->cells[i] == NULL)
			return 0;
		if (i != 0 && x != 0 && content[i] == '\n') {
			x = 0;
			y++;
		} else
			x++;
		map->real_len++;
	}
	return 1;
}

void free_maze(maze_t *map)
{
	if (map->cells != NULL) {
		for (int i = 0; i < map->real_len && map->cells[i]; i++)
			free(map->cells[i]);
		free(map->cells);
	}
	free(map);
}
