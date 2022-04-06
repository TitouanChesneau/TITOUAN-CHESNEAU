/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for solver
*/

#include "dante.h"
#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    if (ac > 3 && my_strcmp(av[3], "perfect") == 1)
        perfect_generator(my_getnbr(av[1]), my_getnbr(av[2]));
    else
        generator(my_getnbr(av[1]), my_getnbr(av[2]));
    return 0;
}
