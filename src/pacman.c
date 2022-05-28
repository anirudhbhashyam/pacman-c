#include "pacman.h"

u_int8_t **init_pacman()
{
    u_int32_t i;
    pacman = malloc(sizeof(u_int8_t *) * PACMAN_SIZE);
    for (i = 0; i < PACMAN_SIZE; i++)
    {
        pacman[i] = malloc(sizeof(u_int8_t) * PACMAN_SIZE);
    }

    pacman[0][0] = ' ';
    pacman[0][1] = '*';
    pacman[0][2] = ' ';
    pacman[1][0] = ' ';
    pacman[1][1] = '*';
    pacman[1][2] = ' ';
    pacman[2][0] = '*';
    pacman[2][1] = '*';
    pacman[2][2] = '*';

    return pacman;
}

void move()
{}