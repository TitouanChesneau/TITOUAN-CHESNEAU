/*
** EPITECH PROJECT, 2022
** my_arrdup
** File description:
** duplicate an array into another
*/

#include <unistd.h>
#include <stdlib.h>

int my_arrlen(char **arr);

void my_strcpy(char *s1, char *s2);

int my_strlen(char const *str);

char **my_arrdup(char **arr)
{
    int i;
    char **dest = malloc((my_arrlen(arr) + 1) * sizeof(char *));

    for (i = 0; arr[i] != NULL; ++i) {
        dest[i] = malloc ((my_strlen(arr[i]) + 1) * sizeof(char));
        my_strcpy(dest[i], arr[i]);
    }
    dest[i] = NULL;
    return dest;
}
