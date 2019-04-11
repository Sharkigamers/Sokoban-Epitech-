/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** find the size of the map
*/

int count_char(char *map)
{
    int max_char = 0;
    int k = 1;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            k = 0;
            i ++;
        }
        if (k > max_char)
            max_char = k;
        k++;
    }
    return (max_char);
}

int count_line(char *map)
{
    int max_line = 1;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            max_line++;
    }
    return (max_line);
}
