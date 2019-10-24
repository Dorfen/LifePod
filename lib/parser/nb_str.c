/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/nb-str.c
*/

#include "parser.h"

int nb_str(char const *str, char const *se, bool const val)
{
    int i = 0;
    int ret = 1;
    char quote = 0;

    if (str == NULL || se == NULL)
        return -1;
    if (str[0] == '\0')
        return 0;
    for (i = 0; str[i] != '\0' && is_separated(str, se, i) == 1; i++);
    for (; str[i] != '\0'; i++) {
        if (val == true)
            quote = is_quote(str, i, quote);
        if (quote != 0)
            continue;
        if (is_separated(str, se, i) == 1 &&
           (is_separated(str, se, i + 1) == 0 && str[i + 1] != '\0'))
            ret++;
    }
    return(ret);
}
