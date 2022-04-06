/*
** EPITECH PROJECT, 2022
** error_handling.c
** File description:
** functions that handle errors
*/

#include <unistd.h>
#include "my.h"

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 4) {
        write(2, "ERROR: invalid number of parameters.\n", 37);
        return 84;
    }
    if (ac > 3 && my_strcmp(av[3], "perfect") == 0) {
        write(2, "ERROR: invalid parameter.\n", 26);
        return 84;
    }
    if (verify_is_str_num(av[1]) == 1 || verify_is_str_num(av[2]) == 1) {
        write(2, "ERROR: parameters must be numbers.\n", 35);
        return 84;
    }
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[2]) < 1) {
        write(2, "ERROR: invalid numbers.\n", 24);
        return 84;
    }
    return 0;
}
