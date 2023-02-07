/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:41:56 by dgross            #+#    #+#             */
/*   Updated: 2023/02/07 14:14:00 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h> 

void	init_map(t_cub3d *cube)
{
	cube->data.north = NULL;
	cube->data.south = NULL;
	cube->data.west = NULL;
	cube->data.east = NULL;
	cube->data.ceiling = 0;
	cube->data.floor = 0;
	cube->data.map = NULL;
	cube->data.width = -1;
	cube->data.height = -1;
}

void	init_player(t_cub3d *cube)
{
	cube->player.facing = '\0';
	cube->player.xppos = 0;
	cube->player.yppos = 0;
	cube->player.xpdir = 0;
	cube->player.ypdir = 0;
	cube->player.plane_x = 0;
	cube->player.plane_y = 0;
}

void	init_gc(t_cub3d *cube)
{
	cube->gc.bin = malloc(sizeof(t_bin));
	if (!cube->gc.bin)
		print_error(cube, "gc bin init fail");
	cube->gc.bin->garbage = NULL;
	cube->gc.bin->next = NULL;
	cube->gc.dump = malloc(sizeof(t_dump));
	if (!cube->gc.dump)
		print_error(cube, "gc dump init fail");
	cube->gc.dump->garbage_pile = NULL;
	cube->gc.dump->next = NULL;
	cube->gc.bin_status = 1;
	cube->gc.dump_status = 1;
}

void	init_cub3d(t_cub3d *cube)
{
	init_gc(cube);
	cube->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (cube->mlx == NULL)
		print_error(cube, "initialization of MLX failed ❗");
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		print_error(cube, "initialization of IMG failed ❗");
	init_map(cube);
	init_player(cube);
	cube->input = NULL;
	cube->c_set = 0;
	cube->f_set = 0;
}

void	init_textures(t_cub3d *cube)
{
	cube->tex.north = mlx_load_png(cube->data.north);
	cube->tex.west = mlx_load_png(cube->data.west);
	cube->tex.south = mlx_load_png(cube->data.south);
	cube->tex.east = mlx_load_png(cube->data.east);
	if (cube->tex.north == NULL || cube->tex.south == NULL
		||cube->tex.west == NULL || cube->tex.east == NULL)
		print_error(cube, "MLX PNG ERROR\n");
}
