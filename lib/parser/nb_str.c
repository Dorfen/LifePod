/*
** EPITECH PROJECT, 2019
** parser
** File description:
** lib/parser/nb-str.c
*/

#include "parser.h"

int nb_str(char const *str, char const *seperator, bool const val)
{
    int ret = 1;
    char quote = 0;

    if (str == NULL || seperator == NULL)
        return -1;
    if (str[0] == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (val == true)
            quote = is_quote(str, i, quote);
        if (quote != 0)
            continue;
        if (is_separated(str, seperator, i) == 1 && str[i + 1] != '\0')
            ret++;
    }
    return(ret);
}
