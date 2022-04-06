/*
** EPITECH PROJECT, 2021
** reverse string
** File description:
** function that reverses a string
*/

#include "../../includes/my.h"

char *my_revstr(char *str)
{
    int temp;
    int length = my_strlen(str) - 1;

    for (int i = 0; i < length; i++) {
        temp = str[length];
        str[length] = str[i];
        str[i] = temp;
        length--;
    }
    return (str);
}
