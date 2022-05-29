#include "utils.h"

void free_resource_2d(u_int8_t **resource, const size_t rows)
{
    u_int32_t i;
    for (i = 0; i < rows; i++)
    {
        if (resource[i] != NULL)
            free(resource[i]);
    }

    if (resource != NULL)
        free(resource);
}