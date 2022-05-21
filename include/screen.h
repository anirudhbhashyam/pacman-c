#define WINDOW_SIZE 50
#define BOUNDARY_LAYER_WIDTH 3

static char window[WINDOW_SIZE][WINDOW_SIZE];

void generate_window();
void layer_create_cross(const int, const int, const int, const int, const int, const int);
void print_window();