/*
** EPITECH PROJECT, 2019
** parser
** File description:
** include/parser.h
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "my.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define T_QUO 1
#define T_SQUO 2
#define T_PAR 4
#define T_TICK 8

int nb_str(char const *str, char const *seperator, bool const quote);
char is_quote(char const *str, int const i, char quote);
int is_separated(char const *str, char const *c, int const j);
char *isolate_str(char const *str, char const *sep, int const i, bool const val);
char **parse_str(char const *str, char const *separator, bool const quote);

#endif
