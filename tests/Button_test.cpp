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
