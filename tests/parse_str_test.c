/*
** EPITECH PROJECT, 2019
** parser
** File description:
** test/parser.c
*/

#include <criterion/criterion.h>
#include "parser.h"

const char *str_parse = "This is a test";
const int len_s = 14;

Test(parse_str_test, str_is_null)
{
    cr_assert_eq(parse_str(NULL, " ", false), NULL);
}

Test(parse_str_test, separator_is_null)
{
    cr_assert_eq(parse_str(str_parse, NULL, false), NULL);
}

Test(parse_str_test, str_tab)
{
    char **tab = parse_str(str_parse, " ", false);

    cr_assert_str_eq(tab[0], "This");
    cr_assert_str_eq(tab[1], "is");
    cr_assert_str_eq(tab[2], "a");
    cr_assert_str_eq(tab[3], "test");
    cr_assert_eq(tab[4], NULL);
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
