/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** stock_map
*/

#include "my.h"

int find_size_of_file(char const *filepath)
{
    struct stat buf;
    int size;

    stat(filepath, &buf);
    if (stat(filepath, &buf) == -1)
        exit(84);
    size = buf.st_size;
    if (size == 0)
        exit(84);
    return size;
}

void save_value(char **f_map, map_t *s_map, int i, int j)
{
    if (f_map[i][j] == 'P') {
        s_map->y = i;
        s_map->x = j;
        s_map->restart.save_y = i;
        s_map->restart.save_x = j;
    }
}

char **malloc_map(char *map, map_t *s_map)
{
    char **f_map;
    int i = 0;
    int j = 0;

    s_map->window.ct_line = count_line(map);
    s_map->window.ct_char = count_char(map);
    f_map = malloc(sizeof(char *) * (s_map->window.ct_line + 1));
    for (int k = 0; map[k] != '\0'; i++) {
        f_map[i] = malloc(sizeof(char *) * (s_map->window.ct_char + 1));
        for (j = 0; map[k] != '\n' && map[k] != '\0'; k++, j++) {
            f_map[i][j] = map[k];
            save_value(f_map, s_map, i, j);
        }
        f_map[i][j] = '\n';
        if (map[k] != '\0')
            k++;
    }
    f_map[i - 1][j] = '\0';
    f_map[i] = NULL;
    return (f_map);
}
