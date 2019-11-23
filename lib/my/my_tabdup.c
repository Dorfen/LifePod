/*
** EPITECH PROJECT, 2019
** LifePod
** File description:
** lib/my/my_tabdup.c
*/

#include "my.h"

char **my_tabdup(char **tab)
{
    char **ret = NULL;
    int len = my_tablen(tab);

    if (tab == NULL || len == -1)
        return NULL;
    ret = malloc(sizeof(char *) * (len + 1));
    if (ret == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        if (tab[i] != NULL)
            ret[i] = my_strdup(tab[i]);
        else
            ret[i] = NULL;
    }
    ret[len] = NULL;
    return ret;
}
