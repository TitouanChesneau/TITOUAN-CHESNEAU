/*
** EPITECH PROJECT, 2022
** Dante_star
** File description:
** reader
*/

#include "dante.h"
#include <stdio.h>

int len_char(char *str, char c)
{
    int len = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            len++;
    return len;
}

char *read_file(char *file_name)
{
    char *buff = NULL;
    int s_size;
    int r_size;
    FILE *handler = fopen(file_name, "r");

    if (handler) {
        fseek(handler, 0, SEEK_END);
        s_size = ftell(handler);
        rewind(handler);
        buff = (char *)malloc(sizeof(char) * (s_size + 1));
        r_size = fread(buff, sizeof(char), s_size, handler);
        buff[s_size] = '\0';
        if (s_size != r_size) {
            free(buff);
            return NULL;
        }
        fclose(handler);
    }
    return buff;
}

char *get_line(char *str, int start)
{
    char *result;
    int i;
    int len = 0;

    for (i = start; i < my_strlen(str) && str[i] != '\n'; i++)
        len++;
    if (len == 0)
        return NULL;
    result = malloc(sizeof(char) * (len + 2));
    for (i = start; str[i] && str[i] != '\n'; i++)
        result[i - start] = str[i];
    result[i - start] = '\0';
    return result;
}
