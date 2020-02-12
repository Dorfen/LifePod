#include "Ship.hpp"
#include <criterion/criterion.h>

Test(Ship, Ship_constuctor)
{
    Ship ship;

    cr_expect_eq(ship.getColon(), 1000);
    cr_expect_eq(ship.getAtm(), 100);
    cr_expect_eq(ship.getGrav(), 100);
    cr_expect_eq(ship.getTemp(), 100);
    cr_expect_eq(ship.getWater(), 100);
    cr_expect_eq(ship.getRes(), 100);
    cr_expect_eq(ship.getLanding(), 100);
    cr_expect_eq(ship.getBuild(), 100);
}

Test(Ship, Ship_dmg_sys)
{
    Ship ship;

    cr_assert_eq(ship.getColon(), 1000);
    ship.damageSys(Ship::Colon, 5);
    cr_assert_eq(ship.getColon(), 995);

    cr_assert_eq(ship.getAtm(), 100);
    ship.damageSys(Ship::Atm, 5);
    cr_assert_eq(ship.getAtm(), 95);

    cr_assert_eq(ship.getGrav(), 100);
    ship.damageSys(Ship::Grav, 5);
    cr_assert_eq(ship.getGrav(), 95);

    cr_assert_eq(ship.getTemp(), 100);
    ship.damageSys(Ship::Temp, 5);
    cr_assert_eq(ship.getTemp(), 95);

    cr_assert_eq(ship.getWater(), 100);
    ship.damageSys(Ship::Water, 5);
    cr_assert_eq(ship.getWater(), 95);

    cr_assert_eq(ship.getRes(), 100);
    ship.damageSys(Ship::Res, 5);
    cr_assert_eq(ship.getRes(), 95);

    cr_assert_eq(ship.getLanding(), 100);
    ship.damageSys(Ship::Landing, 5);
    cr_assert_eq(ship.getLanding(), 95);

    cr_assert_eq(ship.getBuild(), 100);
    ship.damageSys(Ship::Build, 5);
    cr_assert_eq(ship.getBuild(), 95);
}
