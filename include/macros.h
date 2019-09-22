/*
** EPITECH PROJECT, 2018
** macros
** File description:
** file contaning many usefull macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#ifdef __GNUC__
#define __hot_function __attribute__ ((hot))
#define __cold_function __attribute__ ((cold));
#else
#define __hot_function
#define __cold_function
#endif

#define COLON 1
#define ATM 2
#define GRAV 3
#define TEMP 4
#define WATER 5
#define RES 6
#define LAND 7
#define BUILD 8

#define ABS(value) (((value) < (0)) ? (-value) : (value))

#define FREE(_p) free((_p)), (_p) = NULL;

#endif /*MACROS_H_*/
