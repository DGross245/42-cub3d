/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:27:12 by dgross            #+#    #+#             */
/*   Updated: 2023/02/19 09:37:12 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_bonus.h"
#include "cub3d_bonus.h"

#include <math.h> // sqrt pow
#include <stdio.h>

void	calc_player_dir(t_cords *player)
{
	if (player->facing == 'N')
	{
		player->xpdir = -1;
		player->plane_y = 0.80;
	}
	else if (player->facing == 'E')
	{
		player->ypdir = 1;
		player->plane_x = 0.80;
	}
	else if (player->facing == 'S')
	{
		player->xpdir = 1;
		player->plane_y = -0.80;
	}
	else if (player->facing == 'W')
	{
		player->ypdir = -1;
		player->plane_x = -0.80;
	}
}

static void	set_ray(t_cub3d *cube, t_ray	*ray, t_cords *player, int x)
{
	ray->map_x = (int)player->xppos;
	ray->map_y = (int)player->yppos;
	ray->plane_cam = 2 * x / (double)cube->mlx->width - 1;
	ray->raydirx = player->xpdir + ray->plane_cam * player->plane_x;
	ray->raydiry = player->ypdir + ray->plane_cam * player->plane_y;
	ray->deltadisx = fabs(1 / ray->raydirx);
	ray->deltadisy = fabs(1 / ray->raydiry);
	calc_dir(ray, player);
}

void	calc_dir(t_ray	*ray, t_cords *player)
{
	if (ray->raydirx > 0)
	{
		ray->stepx = 1;
		ray->sidedis_x = (ray->map_x + 1 - player->xppos) * ray->deltadisx;
	}
	else
	{
		ray->stepx = -1;
		ray->sidedis_x = (player->xppos - ray->map_x) * ray->deltadisx;
	}
	if (ray->raydiry > 0)
	{
		ray->stepy = 1;
		ray->sidedis_y = (ray->map_y + 1 - player->yppos) * ray->deltadisy;
	}
	else
	{
		ray->stepy = -1;
		ray->sidedis_y = (player->yppos - ray->map_y) * ray->deltadisy;
	}
}

void	calculator(t_cub3d *cube, t_cords *player)
{
	int					x;
	mlx_texture_t		*tex;

	x = -1;
	while (++x < cube->mlx->width)
	{
		paint_bg(cube, x);
		set_ray(cube, &cube->ray, player, x);
		search_wall(cube);
		tex = get_wall_tex(cube);
		calc_wall(cube);
		painter(cube, tex, x);
	}
	mlx_image_to_window(cube->mlx, cube->img, 0, 0);
}

mlx_texture_t	*get_wall_tex(t_cub3d *cube)
{
	mlx_texture_t	*wall_tex;

	wall_tex = NULL;
	if (cube->ray.wall_side == 0)
	{
		if (cube->ray.stepx > 0)
			wall_tex = cube->tex.south;
		else if (cube->ray.stepx < 0)
			wall_tex = cube->tex.north;
	}
	else if (cube->ray.wall_side == 1)
	{
		if (cube->ray.stepy < 0)
			wall_tex = cube->tex.west;
		else if (cube->ray.stepy > 0)
			wall_tex = cube->tex.east;
	}
	return (is_door(cube, wall_tex));
}
