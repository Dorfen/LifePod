/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** sort int
*/

#include "my.h"

void my_sort_int_array(int *tab, int size)
{
    int i;
    int j;
    int temp;
    int mini;

    i = 0;
    j = 0;
    mini = 0;
    while (i < size){
        if (tab[j] < tab[mini]){
            mini = j;
        }
        j = j + 1;
    }
    temp = tab[i];
    tab[i] = tab[mini];
    tab[mini] = temp;
    i = i + 1;
    j = i;
    mini = i;
}
