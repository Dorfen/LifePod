/*
** EPITECH PROJECT, 2019
** parser
** File description:
** test/parser.c
*/

#include <criterion/criterion.h>
#include "parser.h"

const char *quoted = "I said \"hello\"";

Test(is_quote, str_is_null)
{
    cr_assert_eq(is_quote(NULL, 10, 4), -1);
}

Test(is_quote, out_of_bound_i)
{
    cr_assert_eq(is_quote(quoted, 100, 0), -1);
}

Test(is_quote, negative_quote)
{
    cr_assert_eq(is_quote(quoted, 3, -1), -1);
}

Test(is_quote, is_quote_skipped)
{
    char val = 0;

    for (int i = 0; quoted[i] != '\0'; i++) {
        val = is_quote(quoted, i, val);
        if (i >= 7 && i < 13)
          cr_assert_eq(val, 1);
        else
          cr_assert_eq(val, 0);
    }
}

Test(is_quote, false_anwser)
{
    cr_assert_eq(is_quote(quoted, 3, 0), 0);
}

Test(is_quote, true_anwser)
{
    cr_assert_eq(is_quote(quoted, 7, 0), 1);
}

Test(is_quote, true_anwser_plus)
{
    cr_assert_eq(is_quote(quoted, 7, 4), 5);
}
