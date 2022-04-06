/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** main
*/

#include "include/bsq.h"

int main(int argc, char **argv)
{
    if (fs_open_file(argv[1]))
        return (84);
    return (0);
}