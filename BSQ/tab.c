/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** new2
*/

#include "include/bsq.h"

char **malloc_tab(char const *str)
{
    int i = 0;
    int lines = my_getnbr(str);
    char **tab;
    int cols = 0;
    int prev_cols = 0;

    for (prev_cols; str[prev_cols] != '\n'; prev_cols++);
    if (lines == 1)
        for (cols = prev_cols; str[cols] != '\n'; cols++);
    else
        for (cols = prev_cols + 1; str[cols] != '\n'; cols++);
    cols -= prev_cols;
    tab = malloc(sizeof(char *) * (lines + 1));
    for (i = 0; i < lines; i++)
        tab[i] = malloc(sizeof(char) * (cols + 1));
    return (tab);
}

void buff_to_str(char *str)
{
    char **file = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    int size = my_strlen(str);

    for (i = 0; str[i] != '\n'; i++);
    file = malloc_tab(str);
    for (i = i + 1; i <= size; i++) {
        if (str[i] == '\n' && i != size){
            file[k][j] = '\0';
            k++;
            j = 0;
            i++;
        }
        file[k][j++] = str[i];
    }
    file[++k] = NULL;
    free(str);
    find_the_square(file);
}

int error_handler(char *str)
{
    int i = 0;
    int j = 0;
    int lines = 0;
    int len_str = my_strlen(str) - 1;

    for (i; str[i] != '\n'; i++)
        if (str[i] > 57 || str[i] < 48)
            return (84);
    if (i == 0)
        return (84);
    i++;
    for (j = i; str[j] != '\0'; j++)
        if (str[j] != '.' && str[j] != 'o' && str[j] != '\n')
            return (84);
    return (0);
}

int fs_open_file(char const *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer;
    struct stat sd;

    if (fd <= -1)
        return (84);
    if (stat(file_path, &sd) == -1) {
        close(fd);
        return (84);
    }
    buffer = malloc(sd.st_size + sizeof(char));
    if (buffer == NULL)
        return (84);
    read(fd, buffer, sd.st_size);
    close(fd);
    buffer[sd.st_size - 1] = '\0';
    if (error_handler(buffer))
        return (84);
    buff_to_str(buffer);
    return (0);
}

void display_map(char **fullbuff)
{
    int len = my_strlen(fullbuff[0]);

    for (int i = 0; fullbuff[i] != NULL; i++) {
        write(1, fullbuff[i], len);
        write(1, "\n", 1);
    }
}