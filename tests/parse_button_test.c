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

Test(parse_button, valid_input_missing_final_new_line)
{
    const char *str = "Button1:1:10:5";
    button_t *ret = parse_button(str);

    cr_assert_eq(ret->system, 1);
    cr_assert_eq(ret->dmg, 10);
    cr_assert_eq(ret->max_mult, 5);
    cr_assert_str_eq(ret->msg, "Button1");
}

Test(parse_button, invalid_input_missing_one_value)
{
    cr_assert_eq(NULL, parse_button("Button1:10:5\n"));
}

Test(parse_button, invalid_input_random_input)
{
    cr_assert_eq(NULL, parse_button("aidia:od:hpaodapuha:pudgasdaluidzadjnamn"));
}

Test(parse_button, invalid_input_only_name)
{
    cr_assert_eq(NULL, parse_button("Button1\n"));
}

Test(parse_button, invalid_input_empty_str)
{
    cr_assert_eq(NULL, parse_button(""));
}

Test(parse_button, invalid_input_null)
{
    cr_assert_eq(NULL, parse_button(NULL));
}
