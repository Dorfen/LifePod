#include "Button.hpp"
#include <criterion/criterion.h>

Test(Button, Button_constructor_str)
{
    std::string str("Button:2:5:2");
    Button but(str);

    cr_expect_eq(but.getMsg(), "Button");
    cr_expect_eq(but.getSystem(), 2);
    cr_expect_eq(but.getDmg(), 5);
    cr_expect_eq(but.getMult(), 2);
}

Test(Button, Button_constructor_number)
{
    std::string msg("Button");
    Button but(2, 5, 2, msg);

    cr_expect_eq(but.getMsg(), "Button");
    cr_expect_eq(but.getSystem(), 2);
    cr_expect_eq(but.getDmg(), 5);
    cr_expect_eq(but.getMult(), 2);
}

Test(Button, Button_constructor_str_throw)
{
    std::string str("Button:10:5:2");
    cr_assert_throw(Button but (str), ButtonErr);
}

Test(Button, Button_constructor_number_throw)
{
    std::string msg("Button");
    cr_assert_throw(Button(10, 5, 2, msg), ButtonErr);
}

Test(Button, Button_constructor_str_neg_throw)
{
    std::string str("Button:-1:5:2");
    cr_assert_throw(Button but(str), ButtonErr);
}

Test(Button, Button_constructor_number_neg_throw)
{
    std::string msg("Button");
    cr_assert_throw(Button(-1, 5, 2, msg), ButtonErr);
}
