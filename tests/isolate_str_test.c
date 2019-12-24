/*
** EPITECH PROJECT, 2019
** parser
** File description:
** test/parser.c
*/

#include <criterion/criterion.h>
#include "parser.h"

const char *str_extract = "This is a test\n";

Test(is_isolate_str_test, str_is_null)
{
    cr_assert_eq(isolate_str(NULL, "", 1, false), NULL);
}

Test(is_isolate_str_test, sep_is_null)
{
    cr_assert_eq(isolate_str(str_extract, NULL, 1, false), NULL);
}

Test(is_isolate_str_test, nb_is_wrong)
{
    cr_assert_eq(isolate_str(str_extract, " ", -1, false), NULL);
}

Test(is_isolate_str_test, out_of_bound)
{
    cr_assert_eq(isolate_str(str_extract, " ", 100, false), NULL);
}

Test(is_isolate_str_test, true_test_2)
{
    char *res = isolate_str(str_extract, " ", 0, false);
    char const *foo = "This";

    cr_assert_str_eq(res, foo);
    free(res);
}

Test(is_isolate_str_test, true_test)
{
    char *res = isolate_str(str_extract, " ", 5, false);
    char const *foo = "is";

    cr_assert_str_eq(res, foo);
    free(res);
}
