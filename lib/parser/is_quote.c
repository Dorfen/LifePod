/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/is_quote.c
*/

#include "parser.h"

char is_quote(char const *str, int const i, char quote)
{
    if (str == NULL || quote == -1)
        return -1;
    if ((size_t)i >= strlen(str))
        return -1;
    if (i > 0)
        if (str[i - 1] == '\\')
            return (quote);
    if (str[i] == '"')
        quote = quote ^ T_QUO;
    if (str[i] == '\'')
        quote = quote ^ T_SQUO;
    if (str[i] == '(' || str[i] == ')')
        quote = quote ^ T_PAR;
    if (str[i] == '`')
        quote = quote ^ T_TICK;
    return (quote);
}
