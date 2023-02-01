/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:41:56 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 13:57:56 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "macros.h"

#include <stdio.h>

void	init_mlx(t_cub3d *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (cube->mlx == NULL)
		print_error("initialization of MLX failed ❗");
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		print_error("initialization of IMG failed ❗");
}

void	init_map(t_cub3d *cube)
{
	cube->data.north = NULL;
	cube->data.south = NULL;
	cube->data.west = NULL;
	cube->data.east = NULL;
	cube->data.ceiling = ft_strdup("");
	cube->data.floor = ft_strdup("");
	cube->data.map = NULL;
	cube->data.width = -1;
	cube->data.height = -1;
}

void	init_player(t_cub3d *cube)
{
	cube->player.facing = '\0';
	cube->player.xppos = -1;
	cube->player.yppos = -1;
	cube->player.xpdir = -1;
	cube->player.ypdir = -1;
}

void	init_dot(t_cub3d *cube)
{
	cube->dot.camx = -1;
	cube->dot.raydirx = -1;
	cube->dot.raydiry = -1;
	cube->dot.rayx = -1;
	cube->dot.rayy = -1;
	cube->dot.deltadisx = -1;
	cube->dot.deltadisy = -1;
	cube->dot.map_x = -1;
	cube->dot.map_y = -1;
	cube->dot.sidedis_x = -1;
	cube->dot.sidedis_y = -1;
}

void	init_cub3d(t_cub3d *cube)
{
	init_mlx(cube);
	init_map(cube);
	init_player(cube);
	init_dot(cube);
	cube->input = NULL;
}
