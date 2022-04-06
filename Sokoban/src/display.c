/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** display
*/

#include "sokoban.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, ");
    my_putstr("containing '#' for walls, 'p' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
}

void display_map(map_t *MAP)
{
	pos_t pos;

	for (int i = 0; i < MAP->rows; i++) {
		pos.x = ((LINES - MAP->rows) / 2) + i;
		pos.y = (COLS - MAP->cols) / 2;
		mvprintw(pos.x, pos.y, MAP->map[i]);
	}
}