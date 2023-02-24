/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:53:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/23 13:57:25 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"
#include "libft.h" // ft_strlen

#include <unistd.h> // write
#include <stdlib.h> // exit

void	print_error(t_cub3d *cube, char *reason)
{
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	write(2, "\n", 1);
	nuke_trash(cube);
	mlx_terminate(cube->mlx);
	exit(1);
}

void	check_png(t_cub3d *cube)
{
	if (!cube->data.north || ft_strncmp(cube->data.north + \
		(ft_strlen(cube->data.north) - 4), ".png", 4) != 0)
		print_error(cube, "texture must be png ❗");
	if (!cube->data.south || ft_strncmp(cube->data.south + \
		(ft_strlen(cube->data.south) - 4), ".png", 4) != 0)
		print_error(cube, "texture must be png ❗");
	if (!cube->data.west || ft_strncmp(cube->data.west + \
		(ft_strlen(cube->data.west) - 4), ".png", 4) != 0)
		print_error(cube, "texture must be png ❗");
	if (!cube->data.east || ft_strncmp(cube->data.east + \
		(ft_strlen(cube->data.east) - 4), ".png", 4) != 0)
		print_error(cube, "texture must be png ❗");
}
