/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy str to another on
*/

#include "../../includes/my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i <= my_strlen(src); i++) {
        dest[i] = src[i];
    }
    return (dest);
}
