/*
** PROJECT, 2019
** LifePod
** File description:
** lib/mycurs/nc_waitforinput.c
*/

#include "my_curse.h"

int nc_waitfor(int key)
{
    while (getch() != key);
    return (key);
}
