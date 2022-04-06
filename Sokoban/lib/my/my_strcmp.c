/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** reproduce the linux my_strcmp function but our one
*/

#include "../../includes/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int length_s1 = my_strlen(s1);
    int length_s2 = my_strlen(s2);

    if (length_s1 - length_s2 == 0) {
        return (0);
    }
    if (length_s1 - length_s2 > 0) {
        return (length_s1 - length_s2);
    }
    return (length_s1 - length_s2);
}
