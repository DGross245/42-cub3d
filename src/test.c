#include "cub3d.h"
#include <stdio.h>

void	print_map(t_cub3d *cube)
{
	int	i;

	i = -1;
	while (cube->input[++i] != NULL)
		printf("%s\n", cube->input[i]);
}

void	print_data(t_map data)
{
	int	i;

	i = -1;
	printf("%s\n", data.north);
	printf("%s\n", data.south);
	printf("%s\n", data.east);
	printf("%s\n", data.west);
	printf("%s\n", data.ceiling);
	printf("%s\n", data.floor);
	while (data.map[++i] != NULL)
		printf("%s\n", data.map[i]);
}
