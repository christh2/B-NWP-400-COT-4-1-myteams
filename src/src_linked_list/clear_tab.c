/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../libs/include/list.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
