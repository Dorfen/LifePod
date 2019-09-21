/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/parse-str.c
*/

#include "parser.h"

char **parse_str(char const *str, char const *separator, bool const quote)
{
    char **ret = NULL;
    int cur = 0;
    int nb = nb_str(str, separator, quote);

    if (str == NULL || separator == NULL || nb == -1)
        return (NULL);
    ret = malloc(sizeof(char *) * (nb + 1));
    if (ret == NULL)
        return NULL;
    ret[nb] = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        ret[cur++] = isolate_str(str, separator, i, quote);
        for(;is_separated(str, separator, i) == 0 && str[i + 1] != '\0'; i++);
    }
    return (ret);
}
