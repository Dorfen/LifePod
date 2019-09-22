/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/isolate_str.c
*/

#include "parser.h"

static char *extract(char *dest, char const *src, int s, int e)
{
    int i = 0;

    for (; s <= e && src[s] != '\0'; s++)
        dest[i++] = src[s];
    dest[i] = '\0';
    return (dest);
}

char *isolate_str(char const *str, char const *sep, int const i, bool val)
{
    int j = i;
    char *ret = NULL;

    if (str == NULL || sep == NULL || i < 0 || (size_t)i > strlen(str))
        return (NULL);
    if (val == false)
        for (; is_separated(str, sep, j) == 0; j++);
    ret = malloc(sizeof(char) * ((j - i) + 1));
    if (ret == NULL)
        return NULL;
    ret[j - i] = '\0';
    ret = extract(ret, str, i, j - 1);
    return (ret);
}
