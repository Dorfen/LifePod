/*
** PROJECT, 2019
** lifepod
** File description:
** header
*/

#define _GNU_SOURCE
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "my_curse.h"
#include "parser.h"
#include "my.h"
#include "screen.h"
#include "macros.h"

#ifndef LIFEPOD_H_
#define LIFEPOD_H_

#define COLON 1
#define ATM 2
#define GRAV 3
#define TEMP 4
#define WATER 5
#define RES 6
#define LAND 7
#define BUILD 8

#define OPT_ONE 'a'
#define OPT_TWO 'z'
#define OPT_THREE 'e'
#define OPT_FOUR 'r'
#define OPT_QUIT 'q'

#define EVENT_NUM 5
#define EVENT_DIR "./event_data/"

typedef struct button_s {
    short system;
    int dmg;
    int max_mult;
    char *msg;
} button_t;

typedef struct event_s {
    char **tab;
    int nb_buttons;
    button_t **button;
} event_t;

typedef struct scan_s {
    int atm;
    int grav;
    int temp;
    int water;
    int res;
} scan_t;

typedef struct ship_s {
    int colon;
    scan_t *scan;
    int landing;
    int build;
} ship_t;

scan_t *alloc_scan(void);
ship_t *alloc_ship(void);
event_t *alloc_event(void);
button_t *alloc_button(void);

int game(scr_t *scr, ship_t *ship, event_t **event);

void refresh_all(scr_t *scr);
void title_win(scr_t *scr);
void display_ship_status(WINDOW *scr, ship_t *ship);

void print_ship(WINDOW *win, int const y, int const x);

button_t *parse_button(char const * const buffer);
event_t *parse_event(char const *buffer);
event_t **load_all_event(void);

void free_tab(char **tab);
void free_event(event_t **event);

bool is_event_loaded(event_t *event);
int event_related(WINDOW *win, WINDOW *cmd, event_t *event);

bool is_good_input(unsigned int nb_buttons, char input);
ship_t *apply_effect(ship_t *ship, const button_t *button);
int button_related(ship_t *ship, event_t *event);

#endif /*LIFEPOD_H_*/
