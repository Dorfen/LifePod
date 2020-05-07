#include "Ship.hpp"
#include <criterion/criterion.h>

Test(Ship, Ship_constuctor)
{
    Ship ship;

    cr_expect_eq(ship.getSystemValue(Ship::Colon), 1000);
    cr_expect_eq(ship.getSystemValue(Ship::Atm), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Grav), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Temp), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Water), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Res), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Landing), 100);
    cr_expect_eq(ship.getSystemValue(Ship::Build), 100);
}

Test(Ship, Ship_dmg_sys)
{
    Ship ship;

    cr_assert_eq(ship.getSystemValue(Ship::Colon), 1000);
    ship.damageSys(Ship::Colon, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Colon), 995);

    cr_assert_eq(ship.getSystemValue(Ship::Atm), 100);
    ship.damageSys(Ship::Atm, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Atm), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Grav), 100);
    ship.damageSys(Ship::Grav, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Grav), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Temp), 100);
    ship.damageSys(Ship::Temp, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Temp), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Water), 100);
    ship.damageSys(Ship::Water, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Water), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Res), 100);
    ship.damageSys(Ship::Res, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Res), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Landing), 100);
    ship.damageSys(Ship::Landing, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Landing), 95);

    cr_assert_eq(ship.getSystemValue(Ship::Build), 100);
    ship.damageSys(Ship::Build, 5);
    cr_assert_eq(ship.getSystemValue(Ship::Build), 95);
}
