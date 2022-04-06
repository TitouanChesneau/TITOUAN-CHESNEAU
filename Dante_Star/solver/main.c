/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** main_two
*/

#include "dante.h"
#include <fcntl.h>

static int increment_line(char *content, int i)
{
    if (content[i] == '\n')
        return 1;
    return 0;
}

static int increment_tmp(char *content, int i, int line)
{
    if (line != 0 && content[i] == '\n')
        return 1;
    return 0;
}

static int check_file(char *content)
{
    int map_width = 0;
    int line = 0;
    int tmp = 0;
    char cells_stock[3] = { '*', 'X', 'o' };

    if (content == NULL || my_strlen(content) < 5)
    return 0;
    map_width = get_map_width(content);
    for (int i = 0; content[i]; i++) {
        if (content[i] != cells_stock[EMPTY] &&
            content[i] != cells_stock[FILL] && content[i] != '\n')
            return 0;
        line += increment_line(content, i);
        if (line != 0 && content[i] == '\n'
            && i - (line * map_width) - tmp != 0)
            return 0;
        tmp += increment_tmp(content, i, line);
    }
    return 1;
}

int main(int ac, char **av)
{
    maze_t *map = NULL;
    char *file_name = av[1];
    char *content = read_file(file_name);

    srand(time(NULL));
    if (ac != 2 || !file_name ||
        open(file_name, O_RDONLY) <= 0 ||
        check_file(content) == false ||
        (map = get_maze(file_name)) == NULL ||
        !map->cells[0] || !map->cells[map->real_len - 1])
        return 84;
    process(map);
    free_maze(map);
    if (content != NULL)
        free(content);
    return 0;
}
