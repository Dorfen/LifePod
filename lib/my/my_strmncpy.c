/*
** PROJECT, 2019
** libmy
** File description:
** copty from to
*/

char *my_strmncpy(char *dest, char *src, int s, int e)
{
    int i = 0;

    for (; s <= e && src[s] != '\0'; s++)
        dest[i++] = src[s];
    dest[i] = '\0';
    return (dest);
}
