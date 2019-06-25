/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr.c
*/

int count_digit(char *str)
{
    int result;
    result = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++result;
    }
    return (result);
}

void rev_str(char *str1, int digit)
{
    char str2[digit + 1];
    for (int i = 1; i <= digit; ++i) {
        str2[i - 1] = str1[digit - i];
    }
    for (int i = 0; i < digit; ++i) {
        str1[i] = str2[i];
    }
}

char *my_revstr(char *str)
{
    int digits;
    digits = count_digit(&str[0]);
    rev_str(&str[0], digits);
    return (&str[0]);
}
