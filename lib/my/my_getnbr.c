/*
** PROJECT, 2018
** my_getnbr
** File description:
** get nb
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int a = 0;

    while (str[a] != '\0'){
        while (48 > str[a] && str[a] > 57){
            a = a + 1;
        }
        if (str[a - 1] == '-'){
            my_putchar('-');
        }
        while (48 <= str[a] && str[a] <= 57){
            my_putchar(str[a] + 48);
            a = a + 1;
        }
    }
    return (0);
}
