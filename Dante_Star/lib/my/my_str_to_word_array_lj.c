/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** transform an str to a word array handling \n
*/

#include <stdlib.h>
#include "my.h"

static int count_spaces(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\n' && i != 0)
            ++count;
    }
    return count;
}

static int is_good_char(char c)
{
    if (c == '\n' || c == '\0')
        return 1;
    if (c >= 32 && c <= 126)
        return 0;
    return 1;
}

static void go_after_space_tabs(char *str)
{
    while (str[0] == '\n') {
        str++;
    }
}

char **my_str_to_word_array_lj(char *str)
{
    int i;
    int wcount = count_spaces(str);
    char **array = malloc((wcount + 1) * sizeof(char *));

    for (i = 0; i < wcount; ++i)
        array[i] = malloc((my_strlen(str) + 1) * sizeof(char));
    array[i] = NULL;
    for (int j = 0; j < wcount; ++j) {
        for (i = 0; is_good_char(str[0]) == 0; ++i) {
            array[j][i] = str[0];
            str++;
        }
        array[j][i] = '\0';
        str++;
        go_after_space_tabs(str);
    }
    return array;
}
