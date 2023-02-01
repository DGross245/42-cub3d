/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:06 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 18:03:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "cub3d.h"

void	calc_player_dir(t_cords *player)
{
	if (player->facing == 'N')
		player->xpdir = 0;
	else if (player->facing == 'E')
	{
		player->xpdir = 1;
		player->ypdir = 0;
	}
	else if (player->facing == 'S')
	{
		player->xpdir = 0;
		player->ypdir = 1;
	}
	else if (player->facing == 'W')
		player->ypdir = 0;
}

void	set_dot(t_cub3d *cube, t_cords *player, int x)
{
	cube->dot.camx = 2 * x / cube->data.width - 1;
	cube->dot.raydirx = player->xpdir * 0 * cube->dot.camx;
	cube->dot.raydiry = player->ypdir * 0.66 * cube->dot.camx;
	cube->dot.deltadisx = ft_abs(1 / cube->dot.raydirx);
	cube->dot.deltadisy = ft_abs(1 / cube->dot.raydiry);
	cube->dot.map_x = (int)cube->player.xppos;
	cube->dot.map_y = (int)cube->player.yppos;
	cube->dot.wall_hit = 0;
}

void	calc_dir(t_points	*dot, t_cords *player)
{
	if (dot->raydirx > 0)
	{
		dot->stepx = 1;
		dot->sidedis_x = (dot->map_x + 1 - player->xppos) * dot->sidedis_x;
	}
	else
	{
		dot->stepx = -1;
		dot->sidedis_x = (player->xppos + dot->map_x) * dot->sidedis_x;
	}
	if (dot->raydiry > 0)
	{
		dot->stepy = 1;
		dot->sidedis_y = (dot->map_y + 1 - player->yppos) * dot->sidedis_y;
	}
	else
	{
		dot->stepy = -1;
		dot->sidedis_y = (player->yppos + dot->map_y) * dot->sidedis_y;
	}
}

void	calculator(t_cub3d *cube, t_cords *player)
{
	int	x;
	int	wall_dist;

	x = -1;
	while (++x < cube->data.width)
	{
		set_dot(cube, player, x);
		calc_dir(&cube->dot, player);
		wall_dist = find_wall(cube);
		get_wall();
		painter(cube, wall_dist);
	}
	//mlx_image_to_window(cube->mlx, cube->img, 0, 0);
}
