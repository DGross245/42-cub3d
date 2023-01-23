/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:41:56 by dgross            #+#    #+#             */
/*   Updated: 2023/01/23 21:10:53 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#include <stdio.h>

void	init_mlx(t_cub3d *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (cube->mlx == NULL)
		print_error("initialization of MLX failed ❗");
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		print_error("initialization of IMG failed ❗");
}

void	init_map(t_cub3d *cube)
{
	cube->data.north = -1;
	cube->data.south = -1;
	cube->data.west = -1;
	cube->data.east = -1;
	cube->data.ceiling = ft_strdup("");
	cube->data.floor = ft_strdup("");
	cube->data.map = NULL;
}

void	init_cub3d(t_cub3d *cube)
{
	init_mlx(cube);
	init_map(cube);
	cube->input = NULL;
}
