/*
** EPITECH PROJECT, 2019
** parser
** File description:
** test/parser.c
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(nb_str_test, str_is_null)
{
    cr_assert_eq(nb_str(NULL, "foobar", false), -1);
}

Test(nb_str_test, seperator_is_null)
{
    cr_assert_eq(nb_str("foobar", NULL, false), -1);
}

Test(nb_str_test, separator_is_empty)
{
    cr_assert_eq(nb_str("foobar", "", false), 1);
}

Test(nb_str_test, str_is_empty)
{
    cr_assert_eq(nb_str("", " ", false), 0);
}

Test(nb_str_test, one_word)
{
    cr_assert_eq(nb_str("foobar", " ", false), 1);
}

Test(nb_str_test, multiple_world)
{
    cr_assert_eq(nb_str("This is a test", " ", true), 4);
}

Test(nb_str_test, skip_quote)
{
    cr_assert_eq(nb_str("I said \"hello world\"", " ", false), 4);
}

Test(nb_str_test, false_skip_quote)
{
    cr_assert_eq(nb_str("I said \"hello world\"", " ", true), 3);
}

Test(nb_str_test, multiple_sep)
{
    cr_assert_eq(nb_str("ls hu;cat", " ;", true), 3);
}
