/*
** EPITECH PROJECT, 2020
** LifePod
** File description:
** tests/is_good_input_test.c
*/

#include "lifepod.h"
#include <criterion/criterion.h>

Test(is_good_input_test, quit_button)
{
    cr_assert(is_good_input(1, OPT_QUIT));
}

Test(is_good_input_test, one_good_button)
{
    cr_assert(is_good_input(1, OPT_ONE));
}

Test(is_good_input_test, two_good_button)
{
    cr_expect(is_good_input(2, OPT_ONE));
    cr_expect(is_good_input(2, OPT_TWO));
}

Test(is_good_input_test, three_good_button)
{
    cr_expect(is_good_input(3, OPT_ONE));
    cr_expect(is_good_input(3, OPT_TWO));
    cr_expect(is_good_input(3, OPT_THREE));
}
Test(is_good_input_test, four_good_button)
{
    cr_expect(is_good_input(4, OPT_ONE));
    cr_expect(is_good_input(4, OPT_TWO));
    cr_expect(is_good_input(4, OPT_THREE));
    cr_expect(is_good_input(4, OPT_FOUR));
}

Test(is_good_input_test, one_bad_button)
{
    cr_expect(is_good_input(1, OPT_ONE));
    cr_expect_not(is_good_input(1, OPT_TWO));
    cr_expect_not(is_good_input(1, OPT_THREE));
    cr_expect_not(is_good_input(1, OPT_FOUR));
}

Test(is_good_input_test, two_bad_button)
{
    cr_expect(is_good_input(2, OPT_ONE));
    cr_expect(is_good_input(2, OPT_TWO));
    cr_expect_not(is_good_input(2, OPT_THREE));
    cr_expect_not(is_good_input(2, OPT_FOUR));
}

Test(is_good_input_test, three_bad_button)
{
    cr_expect(is_good_input(3, OPT_ONE));
    cr_expect(is_good_input(3, OPT_TWO));
    cr_expect(is_good_input(3, OPT_THREE));
    cr_expect_not(is_good_input(3, OPT_FOUR));
}
