/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** recreate the sokoban
*/

#include "my.h"

char *stock_map(map_t *s_map, char *map, int fd, int size)
{
    int count_player = 0;

    if (read(fd, map, size) == -1)
        exit(84);
    map[size] = '\0';
    s_map->final_map = malloc_map(map, s_map);
    s_map->clone_map = malloc_map(map, s_map);
    for (int i = 0; map[i] != '\0'; i++) {
        map[i] == 'P' ? count_player++ : 0;
        if (map[i] != 'P' && map[i] != 'X' && map[i] != '\n' && map[i] != ' ' &&
            map[i] != '#' && map[i] != 'O') {
            write(1, "Only certain objects are alow in the map !\n", 43);
            exit(84);
        }
    }
    if (count_player != 1) {
        write(1, "Put only one player on the map !\n", 33);
        exit(84);
    }
    return (map);
}

void window_size(map_t *s_map)
{
    if (LINES < s_map->window.ct_char || COLS < s_map->window.ct_line) {
        while (LINES < s_map->window.ct_char || COLS < s_map->window.ct_line) {
            clear();
            mvprintw(LINES / 2, COLS / 2 - 14, "Window's size is not enought");
            refresh();
        }
    }
}

int sokoban(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = find_size_of_file(filepath);
    char *map = malloc(sizeof(char) * (size + 1));
    char *save_map = map;
    map_t s_map;

    stock_map(&s_map, map, fd, size);
    initscr();
    curs_set(false);
    before_cond(&s_map);
    while (s_map.key != 113) {
        window_size(&s_map);
        s_map.key = getch();
        in_cond(&s_map);
        }
        free(save_map);
    endwin();
    return (0);
}

int main(int ac, char **av)
{
    int fd = open("read_me", O_RDONLY);
    int size = find_size_of_file("read_me");
    char *buffer = malloc(sizeof(char) * (size + 1));
    char *save_buffer = buffer;

    if (ac != 2)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") != 0)
        sokoban(av[1]);
    else if ((my_strcmp(av[0], "./my_sokoban") == 0) &&
            (my_strcmp(av[1], "-h") == 0)) {
        read(fd, buffer, size);
        write(1, buffer, size);
    }
    free(save_buffer);
    close(fd);
    return (0);
}
