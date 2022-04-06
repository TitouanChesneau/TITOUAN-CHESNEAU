/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		exit (84);
	return ptr;
}

map_t *init_map(void)
{
	map_t *MAP = (map_t *)my_malloc(sizeof(map_t));

	MAP->pathname = NULL;
	MAP->head = NULL;
	MAP->ghead = NULL;
	MAP->map = NULL;
	return MAP;
}

int my_print_map(char *pathname)
{
	int ret = 0;
	map_t *MAP = init_map();

	MAP->pathname = pathname;
	my_map(pathname, MAP);
	check(MAP);
	initscr();
	keypad(stdscr, TRUE);
	display_map(MAP);
	ret = game_loop(MAP);
	free_all(MAP);
	return ret;
}

case_t *find_case(pos_t pos, case_t *head)
{
	case_t *current = head;

	while (current) {
		if (pos.x == current->pos.x && pos.y == current->pos.y)
			return current;
		current = current->next;
	}
	return NULL;
}

int main(int ac, char **av)
{
	int ret = 0;

	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0)
			print_help();
		ret = my_print_map(av[1]);
		endwin();
	} else {
		my_putstr("error : too many parrameters but need 1\n");
		return 84;
	}
	return ret;
}