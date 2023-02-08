/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:13:26 by dna               #+#    #+#             */
/*   Updated: 2023/02/08 12:17:10 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "execution.h"

static void	open_door(t_cub3d *cube, double tmp_x, double tmp_y)
{
	cube->data.map[(int)tmp_x][(int)tmp_y] = '3';
	mlx_delete_texture(cube->tex.door);
	cube->tex.door = mlx_load_png("./textures/open_door.png");
}

static void	close_door(t_cub3d *cube, double tmp_x, double tmp_y)
{
	cube->data.map[(int)tmp_x][(int)tmp_y] = '2';
	mlx_delete_texture(cube->tex.door);
	cube->tex.door = mlx_load_png(cube->data.door);
}

void	door(t_cub3d *cube, t_cords *player)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = ((player->xppos) + player->xpdir * 0.08);
	tmp_y = ((player->yppos) + player->ypdir * 0.08);
	if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '2')
		open_door(cube, tmp_x - 1, tmp_y);
	else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '2')
		open_door(cube, tmp_x + 1, tmp_y);
	else if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '3')
		close_door(cube, tmp_x - 1, tmp_y);
	else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '3')
		close_door(cube, tmp_x + 1, tmp_y);
}
