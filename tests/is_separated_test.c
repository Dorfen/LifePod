/*
** EPITECH PROJECT, 2019
** parser
** File description:
** test/parser.c
*/

#include <criterion/criterion.h>
#include "parser.h"

const char *separator = "This is a test\n";
const int len = 14;

Test(is_separated_fun, str_is_null)
{
    cr_assert_eq(is_separated(NULL, "k", 1), -1);
}

Test(is_separated_fun, c_is_null)
{
    cr_assert_eq(is_separated(separator, NULL, 1), -1);
}

Test(is_separated_fun, out_of_bound_j)
{
    cr_assert_eq(is_separated(separator, "k", 100), -1);
}

Test(is_separated_fun, at_the_limit)
{
    cr_assert_eq(is_separated(separator, " ", len), 0);
}

Test(is_separated_fun, is_true_solution)
{
    cr_assert_eq(is_separated(separator, " ", 4), 1);
}

Test(is_separated_fun, is_false_solution)
{
    cr_assert_eq(is_separated(separator, " ", 3), 0);
}
