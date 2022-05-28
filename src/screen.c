#include "screen.h"

void init_window()
{
    u_int32_t i, j;
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        for (j = 0; j < WINDOW_SIZE; j++)
        {
            window[i][j] = ' ';
        }
    }
    generate_boundaries();
}

void render_window() 
{
    u_int32_t i, j;
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        for (j = 0; j < WINDOW_SIZE; j++)
        {
            printf("%c ", window[i][j]);
        }
        printf("\n");
    }
}

void update_window()
{}

void render_pixels(const u_int8_t **pixels, const u_int32_t pixel_x_size, const u_int32_t pixel_y_size, u_int32_t render_centre_i, u_int32_t render_centre_j)
{
    u_int32_t i, j;
    const u_int32_t render_start_i = render_centre_i - (pixel_x_size / 2);
    const u_int32_t render_end_i = render_centre_i + (pixel_x_size / 2);
    const u_int32_t render_start_j = render_centre_j - (pixel_y_size / 2);
    const u_int32_t render_end_j = render_centre_j + (pixel_y_size / 2);

    for (i = render_start_i; i <= render_end_i; i++)
    {
        for (j = render_start_j; j <= render_end_j; j++)
        {
            if (window[i][j] != ' ') continue;
            window[i][j] = pixels[i - render_start_i][j - render_start_j];
        }
    }
}

void generate_boundaries()
{
    // Create outer walls.
    u_int32_t i, j;
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        for (j = 0; j < WINDOW_SIZE; j++)
        {
            if (i == 0 || i == WINDOW_SIZE - 1 || j == 0 || j == WINDOW_SIZE - 1)
            {
                window[i][j] = '#';
            }
            else
            {
                window[i][j] = ' ';
            }
        }
    }

    const u_int32_t square_boundary_low =  (3 * WINDOW_SIZE) / 8;
    const u_int32_t square_boundary_high = (5 * WINDOW_SIZE) / 8;

    // Create starting box.
    for (i = square_boundary_low; i < square_boundary_high ; i++)
    {
        for (j = square_boundary_low; j < square_boundary_high ; j++)
        {
            if (i == square_boundary_low || i == square_boundary_high - 1 || j == square_boundary_low || j == square_boundary_high - 1)
            {
                window[i][j] = '#';
            }
        }
    }

    // Create first layer boundaries.
    // First layer boundaries start 3 # from the walls.
    // Only top and bottom boundaries are created.
    const u_int32_t first_layer = BOUNDARY_LAYER_WIDTH;
    for (i = first_layer; i < WINDOW_SIZE - first_layer; i++)
    {
        for (j = first_layer; j < WINDOW_SIZE - first_layer; j++)
        {
            if (i == first_layer || i == WINDOW_SIZE - (first_layer + 1))
            {
                window[i][j] = '#';
            }
        }
    }

    // Create second layer boundaries.
    // First layer boundaries start 6 # from the walls.
    // Only left and right boundaries are created.
    const u_int32_t second_layer = BOUNDARY_LAYER_WIDTH * 2;
    for (i = second_layer; i < WINDOW_SIZE - second_layer; i++)
    {
        for (j = second_layer; j < WINDOW_SIZE - second_layer; j++)
        {
            if (j == second_layer || j == WINDOW_SIZE - (second_layer + 1))
            {
                window[i][j] = '#';
            }
        }
    }
    
    // Create third layer boundaries.
    // First layer boundaries start 9 # from the walls.
    // T intersections left and right.
    // This layer creates Ts.
    const u_int32_t third_layer = BOUNDARY_LAYER_WIDTH * 3;
    const u_int32_t temp = third_layer * 3;
    generate_map_obstacles_cross(third_layer, third_layer, third_layer + 8, third_layer + 8, -2, -1);
    generate_map_obstacles_cross(temp, temp, temp + 12, temp + 12, 2, 1); 
}

/*
 * Creates walls in the form 
 *     #
 *     #
 * # # # # # 
 *     #
 *     #
 * Need to specify upper left corner and 
 * lower right corner of the cross. Offsets 
 * can be used to offset the centre of the
 * cross.
 */
void generate_map_obstacles_cross(const u_int32_t upper_left_i, const u_int32_t upper_left_j, const u_int32_t lower_right_i, const u_int32_t lower_right_j, const u_int32_t offset_i, const u_int32_t offset_j)
{
    uint32_t i, j;
    const uint32_t vertical_mean = (upper_left_i + lower_right_i) / 2 + offset_i;
    const uint32_t horizontal_mean = (upper_left_j + lower_right_j) / 2 + offset_j;

    for (i = upper_left_i; i <= lower_right_i; i++)
    {
        window[i][horizontal_mean] = '#';
    }

    for (j = upper_left_j; j <= lower_right_i; j++)
    {
        window[vertical_mean][j] = '#';
    }
}