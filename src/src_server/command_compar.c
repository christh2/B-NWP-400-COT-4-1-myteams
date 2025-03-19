/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include <string.h>
#include <ctype.h>

int command_cmp(const char *str1, const char *str2)
{
    while (*str1 && *str2) {
        if (isspace(*str1) || isspace(*str2))
            break;
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    if (isspace(*str1) || isspace(*str2) || (*str1 == '\0' && *str2 == '\0'))
        return 0;
    return *str1 - *str2;
}
