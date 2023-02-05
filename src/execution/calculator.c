/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:06 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 13:22:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "cub3d.h"
#include "libft.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	calc_player_dir(t_cords *player)
{
	if (player->facing == 'N')
	{
		player->xpdir = -1;
		player->plane_y = 1;
	}
	else if (player->facing == 'E')
	{
		player->ypdir = 1;
		player->plane_x = 1;
	}
	else if (player->facing == 'S')
	{
		player->xpdir = 1;
		player->plane_y = -1;
	}
	else if (player->facing == 'W')
	{
		player->ypdir = -1;
		player->plane_x = -1;
	}
}

void	set_ray(t_ray	*ray, t_cords *player, int x)
{
	ray->camx = 2 * x / (double)WIDTH - 1;
	ray->raydirx = player->xpdir + player->plane_x * ray->camx;
	ray->raydiry = player->ypdir + player->plane_y * ray->camx;
	ray->map_x = (int)player->xppos;
	ray->map_y = (int)player->yppos;
	ray->deltadisx = sqrt(1 + pow(ray->raydiry, 2) / pow(ray->raydirx, 2));
	ray->deltadisy = sqrt(1 + pow(ray->raydirx, 2) / pow(ray->raydiry, 2));
	ray->wall_hit = 0;
}

void	calc_dir(t_ray	*ray, t_cords *player)
{
	if (ray->raydirx > 0)
	{
		ray->stepx = 1;
		ray->sidedis_x = (ray->map_x + 1.0 - player->xppos) * ray->deltadisx;
	}
	else
	{
		ray->stepx = -1;
		ray->sidedis_x = (player->xppos - ray->map_x) * ray->deltadisx;
	}
	if (ray->raydiry > 0)
	{
		ray->stepy = 1;
		ray->sidedis_y = (ray->map_y + 1.0 - player->yppos) * ray->deltadisy;
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
	while (++x < WIDTH)
	{
		set_ray(&cube->ray, player, x);
		calc_dir(&cube->ray, player);
		cube->ray.wall_dist = calc_wall(cube);
		tex = get_wall_tex(cube);
		calc_rest(cube, tex, x);
		paint_bg(cube, x);
	}
	mlx_image_to_window(cube->mlx, cube->img, 0, 0);
}

mlx_texture_t	*get_wall_tex(t_cub3d *cube)
{
	mlx_texture_t	*wall_tex;

	if (cube->ray.wall_side == 1)
	{
		if (cube->ray.stepy < 0)
			wall_tex = cube->tex.north;
		else if (cube->ray.stepy > 0)
			wall_tex = cube->tex.south;
	}
	if (cube->ray.wall_side == 0)
	{
		if (cube->ray.stepx > 0)
			wall_tex = cube->tex.west;
		else if (cube->ray.stepx < 0)
			wall_tex = cube->tex.east;
	}
	return (wall_tex);
}