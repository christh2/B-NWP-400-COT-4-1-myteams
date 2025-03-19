/*
** EPITECH PROJECT, 2022
** array
** File description:
** array
*/
#include <stdio.h>
#include <stdlib.h>
#include "../../libs/include/list.h"

char **array_maker(int rows, char *str, char *delim)
{
    int i;
    int x = 0;
    char **tab;
    char *str1 = strdup(str);
    char *line = strtok(str1, delim);

    tab = (char **)malloc(sizeof(char *) * (rows + 1));
    for (i = 0; i < rows; i++) {
        tab[i] = (char *)malloc(sizeof(char) * (strlen(str)));
        line = strtok(NULL, delim);
        x++;
    }
    tab[rows] = NULL;
    return (tab);
}

char *replace(char *str, char c, char rep)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            str[i] = rep;
    return str;
}

char **alloc_on_str(char *str, char sep)
{
    int rows = 0;
    char **tab;
    int i;
    char delim[2] = {'\t', sep};

    str = replace(str, '\t', sep);
    for (i = 0; str[i] == sep; i++);
    for (; str[i] != '\0'; i++)
        if ((str[i] == sep) && (str[i + 1] != '\0') && (str[i + 1] != '\n')
        && (str[i + 1] != sep))
            rows++;
    tab = array_maker(rows + 1, str, delim);
    return tab;
}

void fill_it_loop(char sep, char *str, char **tab)
{
    char delim[2];
    char *line;
    int i = 0;

    delim[0] = '\t';
    delim[1] = sep;
    line = strtok(str, delim);
    while (line) {
        tab[i] = (char *) malloc((strlen(line) + 1) * sizeof(char));
        if (!tab[i])
            return;
        strcpy(tab[i], line);
        i++;
        line = strtok(NULL, delim);
    }
    tab[i] = NULL;
}

char **fill_it(char *str1, char sep)
{
    char *str;
    char **tab;

    if (!str1)
        return NULL;
    str = strdup(str1);
    if (!str)
        return NULL;
    tab = alloc_on_str(str, sep);
    fill_it_loop(sep, str, tab);
    free(str);
    return tab;
}
