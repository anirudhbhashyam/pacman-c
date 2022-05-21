#include "libs.h"
#include "screen.h"

void generate_window()
{
    int i, j;
    // Create outer walls.
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

    const int square_boundary_low =  (3 * WINDOW_SIZE) / 8;
    const int square_boundary_high = (5 * WINDOW_SIZE) / 8;

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
    const int first_layer = BOUNDARY_LAYER_WIDTH;
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
    const int second_layer = BOUNDARY_LAYER_WIDTH * 2;
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
    const int third_layer = BOUNDARY_LAYER_WIDTH * 3;
    layer_create_cross(third_layer, third_layer, third_layer + 6, third_layer + 6, -2, -1); 
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
void layer_create_cross(const int upper_left_i, const int upper_left_j, const int lower_right_i, const int lower_right_j, const int offset_i, const int offset_j)
{
    int i, j;
    const int vertical_mean = (upper_left_i + lower_right_i) / 2 + offset_i;
    const int horizontal_mean = (upper_left_j + lower_right_j) / 2 + offset_j;
    for (i = upper_left_i; i <= lower_right_i; i++)
    {
        for (j = upper_left_j; j <= lower_right_j; j++)
        {
            if (i == vertical_mean || j == horizontal_mean)
            {
                window[i][j] = '#';
            }
        }
    }
}

void print_window()
{
    int i, j;
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        for (j = 0; j < WINDOW_SIZE; j++)
        {
            printf("%c ", window[i][j]);
        }
        printf("\n");
    }
}