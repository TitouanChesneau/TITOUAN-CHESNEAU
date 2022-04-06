/*
** EPITECH PROJECT, 2022
** dante.h
** File description:
** dante function prototypes, header file
*/

#ifndef DANTE_H_
    #define DANTE_H_

typedef struct {
    int x;
    int y;
} vector2i;

typedef enum {
    right,
    left,
    up,
    down,
    right_up,
    right_down,
    left_up,
    left_down,
    unknown
} direction;

int error_handling(int ac, char **av);

void generator(int x, int y);

void perfect_generator(int x, int y);

void make_perfect_path(char **map, int x, int y);

char **init_map(int x, int y, char c);

int randint(int max);

direction get_direction(int x);

direction get_diag_direction(int x);

vector2i get_vector(int x, int y);

void make_path(char **map, int width, int length);

#endif /* !MY_SOKOBAN_H_ */
