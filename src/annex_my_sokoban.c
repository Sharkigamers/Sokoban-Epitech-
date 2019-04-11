/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** annex for my_sokoban
*/

#include "my.h"

void cond_cond_scan(map_t *s_map, int i, int j)
{
    s_map->clone_map[i][j] != 'O' ? (s_map->loose.bloqued_box)++ : 0;
    if (s_map->loose.bloqued_box == s_map->loose.max_box) {
        endwin();
        write(1, "You lose !\n", 10);
        exit(1);
    }
}

void cond_scan(map_t *s_map, int i, int j, int *save_count)
{
    if (s_map->clone_map[i][j] == 'O' && s_map->final_map[i][j] == ' ')
        s_map->final_map[i][j] = 'O';
    if (s_map->clone_map[i][j] == 'O' && s_map->final_map[i][j] == 'X') {
        (*save_count)++;
    }
    if ((s_map->final_map[i][j] == 'X' && s_map->clone_map[i][j] != 'O') &&
    ((s_map->final_map[i - 1][j] == '#' && s_map->final_map[i][j - 1] == '#') ||
    (s_map->final_map[i][j - 1] == '#' && s_map->final_map[i + 1][j] == '#') ||
    (s_map->final_map[i + 1][j] == '#' && s_map->final_map[i][j + 1] == '#') ||
    (s_map->final_map[i][j + 1] == '#' && s_map->final_map[i - 1][j] == '#'))) {
        cond_cond_scan(s_map, i, j);
    }
    if (*save_count == s_map->restart.max_o) {
        endwin();
        write(1, "You won !\n", 9);
        exit(0);
    }
}

void scan_map(map_t *s_map)
{
    int i = 0;
    int j = 0;
    int save_count = 0;

    s_map->loose.bloqued_box = 0;
    for (; s_map->final_map[i] != NULL; i++) {
        for (j = 0; s_map->final_map[i][j] != '\n'; j++) {
            cond_scan(s_map, i, j, &save_count);
        }
    }
}

void before_cond(map_t *s_map)
{
    s_map->restart.max_o = 0;
    s_map->loose.max_box = 0;
    clear();
    refresh();
    for (int i = 0; s_map->final_map[i] != NULL; i++)
        printw(s_map->final_map[i]);
    for (int i = 0; s_map->final_map[i] != NULL; i++) {
        for (int j = 0; s_map->final_map[i][j] != '\n' &&
                s_map->final_map[i][j] != '\0'; j++) {
            s_map->final_map[i][j] == 'O' ? s_map->restart.max_o++ : 0;
            s_map->final_map[i][j] == 'X' ? s_map->loose.max_box++ : 0;
        }
    }
    if (s_map->restart.max_o > s_map->loose.max_box) {
        endwin();
        write(1, "Not enough boxes !\n", 19);
        exit(84);
    }
    keypad(stdscr, TRUE);
    noecho();
}

void in_cond(map_t *s_map)
{
    clear();
    refresh();
    key_pressed(s_map);
    for (int i = 0; s_map->final_map[i] != NULL; i++)
        printw(s_map->final_map[i]);
}
