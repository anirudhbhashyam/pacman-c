#pragma once

#include "libs.h"

#define PACMAN_SIZE 3

static u_int8_t **pacman;

u_int8_t ** init_pacman();
void move();