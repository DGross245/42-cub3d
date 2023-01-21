#include "cub3d.h"
#include <stdio.h>

void	print_map(t_cub3d *cube)
{
	int	i;

	i = -1;
	while (cube->input[++i] != NULL)
		printf("%s\n", cube->input[i]);
}
