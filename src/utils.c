#include "utils.h"


void free_resources(u_int8_t **resource, const size_t rows)
{
	u_int32_t i;
	for (i = 0; i < rows; i++)
	{
		free(resource[i]);
	}
	free(resource);
}