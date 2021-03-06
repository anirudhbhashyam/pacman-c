#pragma once

#include "libs.h"
#include "pacman.h"
#include "utils.h"

#define WINDOW_SIZE 50
#define BOUNDARY_LAYER_WIDTH 3

static u_int8_t window[WINDOW_SIZE][WINDOW_SIZE];

void init_window();
void render_window();
void update_window();

void render_pixels(const u_int8_t**, const size_t, const size_t, const u_int32_t, const u_int32_t);
void generate_boundaries();
void generate_map_obstacles_cross();
void layer_create_cross(const u_int32_t, const u_int32_t, const u_int32_t, const u_int32_t, const u_int32_t, const u_int32_t);