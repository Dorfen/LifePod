/*
** PROJECT, 2019
** lifepod
** File description:
** header
*/

#ifndef LIFEPOD_H_
#define LIFEPOD_H_

#include "my_curse.h"
#include "my.h"
#include "macros.h"

typedef struct scr_s {
    WINDOW *event;
    WINDOW *cmd;
    WINDOW *status;
} scr_t;

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

int game(ship_t *ship);

scr_t *build_scr_t(void);

#endif /*LIFEPOD_H_*/
