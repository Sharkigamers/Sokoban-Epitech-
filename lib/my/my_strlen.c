/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** strlen
*/

void my_putchar(char);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}
