/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** reproduce my_strstr function of linux
*/

char *my_strstr_pt2 (char *str, char const *to_find, int x)
{
    int true = 0;

    for (int y = 1; to_find[y] != '\0'; y++) {
        if (str[x + y] == to_find[y]) {
            continue;
        } else {
            true = 1;
        }
    }
    return (str + x);
}

char *my_strstr (char *str, char const *to_find)
{
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == to_find[0]) {
            my_strstr_pt2(str, to_find, x);
            return (str + x);
        }
    }
}
