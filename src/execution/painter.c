/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 11:41:32 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <macros.h>

void	calc_rest(t_cub3d *cube, mlx_texture_t *texture, int tex, int x)
{
	double	lheight;
	int		start;
	int		end;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	lheight = HEIGHT / cube->ray.wall_dist;
	start = (-lheight) / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = lheight / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	tex_x = (int)find_wall(cube, cube->ray.wall_dist) * (double)texture->width;
	tex_x = 1 * texture->width / lheight;
	step = ((double)texture->height) / lheight;
	tex_pos = (start - HEIGHT / 2 + lheight / 2) * step - 1;
	cube->ray.start = start;
	cube->ray.end = end;
	while (start < end)
	{
		tex_pos += step;
		tex_y = (int)tex_pos & (texture->height - 1);
		ft_memcpy(&cube->img->pixels[(start * cube->img->width + x) * 4], texture->pixels[(tex_y * texture->height + tex_x) * 4], 4);
		start++;
	}
}

double	find_wall(t_cub3d *cube, double wall_dist)
{
	double	wall_x;

	if (cube->ray.wall_side == 0)
		wall_x = cube->player.yppos - (wall_dist * cube->ray.raydiry);
	else
		wall_x = cube->player.xppos - (wall_dist * cube->ray.raydirx);
	wall_x = wall_x - wall_x;
	return (wall_x);
}

void	paint_bg(t_cub3d	*cube, int x)
{
	int			i;

	i = -1;
	while (++i < HEIGHT)
	{
		if (i <= cube->ray.start)
			mlx_put_pixel(cube->img, x, i, 0x000FFFFF);
		else if (i >= cube->ray.end)
			mlx_put_pixel(cube->img, x, i, 0xF000FFFF);
	}
}
