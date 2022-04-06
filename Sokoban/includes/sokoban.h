/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H__
    #define SOKOBAN_H__

#include "my.h"
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct pos_s {
	int x;
	int y;
} pos_t;

typedef struct x_pos {
	int id;
	pos_t pos;
	struct case_pos *next;
} case_t;

typedef struct o_pos {
	int id;
	pos_t pos;
    struct goal_pos *next;
} goal_t;

typedef struct map_elt {
	int rows;
	int cols;
	int nbr_O;
	int nbr_X;
	pos_t pos_P;
	char *pathname;
	struct case_pos *head;
	struct goal_pos *ghead;
	char **map;
} map_t;

void restart(map_t *MAP);
int game_loop(map_t *MAP);
int check_window(map_t *MAP);
void display_map(map_t *MAP);
void free_all(map_t *MAP);
void *my_malloc(size_t size);
int ui_manager(int ch, map_t *MAP);
void check_goal(map_t *MAP);
case_t *find_case(pos_t pos, case_t *head);
void move_down(map_t *MAP);
void move_right(map_t *MAP);
void move_left(map_t *MAP);
void move_up(map_t *MAP);
int my_print_map(char *pathname);
void check_case(map_t *MAP);
void check(map_t *MAP);
void add_case(map_t *MAP, int i, int j);
void map_len(char *pathname, int *res_col, int *res_row);
char **alloc_2d(int, int);
void my_map(char *pathname, map_t *MAP);
char *my_init(char *str, int len);
void print_help(void);


#endif