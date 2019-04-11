/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** event
*/

#include "my.h"

void key_up(map_t *s_map)
{
    if (s_map->key == KEY_UP) {
        if (s_map->final_map[s_map->y - 1][s_map->x] == 'X' &&
            (s_map->final_map[s_map->y - 2][s_map->x] != '#' &&
            s_map->final_map[s_map->y - 2][s_map->x] != 'X')) {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y - 1][s_map->x] = 'P';
            s_map->final_map[s_map->y - 2][s_map->x] = 'X';
            s_map->y -= 1;
        }
        if (s_map->final_map[s_map->y - 1][s_map->x] != '#' &&
            s_map->final_map[s_map->y - 1][s_map->x] != 'X') {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y - 1][s_map->x] = 'P';
            s_map->y -= 1;
        }
    }
}

void key_down(map_t *s_map)
{
    if (s_map->key == KEY_DOWN) {
        if (s_map->final_map[s_map->y + 1][s_map->x] == 'X' &&
            (s_map->final_map[s_map->y + 2][s_map->x] != '#' &&
            s_map->final_map[s_map->y + 2][s_map->x] != 'X')) {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y + 1][s_map->x] = 'P';
            s_map->final_map[s_map->y + 2][s_map->x] = 'X';
            s_map->y += 1;
        }
        if (s_map->final_map[s_map->y + 1][s_map->x] != '#' &&
            s_map->final_map[s_map->y + 1][s_map->x] != 'X') {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y + 1][s_map->x] = 'P';
            s_map->y += 1;
        }
    }
}

void key_right(map_t *s_map)
{
    if (s_map->key == KEY_RIGHT) {
        if (s_map->final_map[s_map->y][s_map->x + 1] == 'X' &&
            (s_map->final_map[s_map->y][s_map->x + 2] != '#' &&
            s_map->final_map[s_map->y][s_map->x + 2] != 'X')) {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y][s_map->x + 1] = 'P';
            s_map->final_map[s_map->y][s_map->x + 2] = 'X';
            s_map->x += 1;
        }
        if (s_map->final_map[s_map->y][s_map->x + 1] != '#' &&
            s_map->final_map[s_map->y][s_map->x + 1] != 'X') {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y][s_map->x + 1] = 'P';
            s_map->x += 1;
        }
    }
}

void key_left(map_t *s_map)
{
    if (s_map->key == KEY_LEFT) {
        if (s_map->final_map[s_map->y][s_map->x - 1] == 'X' &&
            (s_map->final_map[s_map->y][s_map->x - 2] != '#' &&
            s_map->final_map[s_map->y][s_map->x - 2] != 'X')) {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y][s_map->x - 1] = 'P';
            s_map->final_map[s_map->y][s_map->x - 2] = 'X';
            s_map->x -= 1;
        }
        if (s_map->final_map[s_map->y][s_map->x - 1] != '#' &&
            s_map->final_map[s_map->y][s_map->x - 1] != 'X') {
            s_map->final_map[s_map->y][s_map->x] = ' ';
            s_map->final_map[s_map->y][s_map->x - 1] = 'P';
            s_map->x -= 1;
        }
    }
}

void key_pressed(map_t *s_map)
{
    if (s_map->key == 32) {
        clear();
        refresh();
        for (int i = 0; s_map->clone_map[i] != NULL; i++)
            s_map->final_map[i] = my_strcpy
                (s_map->final_map[i], s_map->clone_map[i]);
        s_map->y = s_map->restart.save_y;
        s_map->x = s_map->restart.save_x;
    }
    key_up(s_map);
    key_down(s_map);
    key_right(s_map);
    key_left(s_map);
    scan_map(s_map);
}
