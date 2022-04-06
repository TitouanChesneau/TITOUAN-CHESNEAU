/*
** EPITECH PROJECT, 2022
** dante.h
** File description:
** dante function prototypes, header file
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "my.h"

#ifndef DANTE_H_
    #define DANTE_H_

typedef struct cell_s {
    int id;
    int x;
    int y;
    int start;
    int end;
    int state;
} cell_t;

typedef struct maze_s {
    cell_t **cells;
    int cells_len;
    int real_len;
    int map_width;
    int map_height;
} maze_t;

enum cell_state {
    EMPTY,
    FILL,
    USED
};

maze_t *get_maze(char *file_name);

cell_t *get_cell(int id, int x, int y, int state);

int check_maze(maze_t *map, char *content);

void free_maze(maze_t *map);

int len_char(char *str, char c);

char *read_file(char *file_name);

char *get_line(char *str, int start);

void process (maze_t *map);

int find_path (maze_t *map, cell_t *start, cell_t *end);

cell_t *find_nearest (maze_t *map, cell_t *current, cell_t *end);

void compute_result (maze_t *map);

int get_map_width(char *str);

int get_map_height(char *str);

void clear_map (maze_t *map);

cell_t *get_cell_by_id(maze_t *map, int id);

int get_state(char c);

int get_distance(cell_t *start, cell_t *end);

cell_t *clean_cell(maze_t *map, cell_t **cell,
cell_t *end, cell_t *current);

bool contain_index(int *buffer, int size, int id);

#endif
