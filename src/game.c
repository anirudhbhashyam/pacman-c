#include "game.h"

void run()
{
    init_window();
    pacman = init_pacman();
    render_pixels(pacman, PACMAN_SIZE, PACMAN_SIZE, 25, 25);

    render_window();
    
    free_resources(pacman, PACMAN_SIZE);
}


