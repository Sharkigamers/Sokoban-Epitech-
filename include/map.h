/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** struct for the map
*/

#ifndef SOKO_
#define SOKO_

#include "my.h"

typedef struct cond_loose
{
    int max_box;
    int bloqued_box;
}loose_t;

typedef struct restart
{
    int save_x;
    int save_y;
    int max_o;
    int restart;
}restart_t;

typedef struct save_window
{
    int ct_line;
    int ct_char;
}s_window_t;

typedef struct my_map
{
    int x;
    int y;
    int key;
    char **final_map;
    char **clone_map;
    loose_t loose;
    restart_t restart;
    s_window_t window;
}map_t;

#endif
