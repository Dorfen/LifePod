/*
** PROJECT, 2019
** LifePod
** File description:
** tests/parse_button_test.c
*/

#include "lifepod.h"
#include <criterion/criterion.h>

Test(parse_button, args_null)
{
    cr_assert_eq(parse_button(NULL), NULL);
}

Test(parse_button, valid_input)
{
    const char *str = "Button1:1:10:5\n";
    button_t *ret = parse_button(str);

    cr_assert_eq(ret->system, 1);
    cr_assert_eq(ret->dmg, 10);
    cr_assert_eq(ret->max_mult, 5);
    cr_assert_str_eq(ret->msg, "Button1");
}
