/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** stock protos
*/

#ifndef MY_
#define MY_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <map.h>

/* lib */

int my_strcmp(char const *s1, char const *s2);
char *my_itoa(int nb);
char *my_strcpy(char *dest, char const *src);

/* annex sokoban */

void cond_scan(map_t *s_map, int i, int j, int *save_count);
void scan_map(map_t *s_map);
void before_cond(map_t *s_map);
void in_cond(map_t *s_map);

/* counter map */

int count_char(char *final_map);
int count_line(char *final_map);

/* stock_map */

int find_size_of_file(char const *filepath);
void save_value(char **f_map, map_t *s_map, int i, int j);
char **malloc_map(char *map, map_t *s_map);

/* event */

void key_up(map_t *s_map);
void key_down(map_t *s_map);
void key_right(map_t *s_map);
void key_left(map_t *s_map);
void key_pressed(map_t *s_map);

#endif
