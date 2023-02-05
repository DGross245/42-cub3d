/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 18:42:59 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <macros.h>

void	calc_rest(t_cub3d *cube, mlx_texture_t *texture, int x)
{
	double	lheight;
	int		start;
	int		end;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	lheight = (int)HEIGHT / cube->ray.wall_dist;
	start = (-lheight) / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = lheight / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	tex_x = (int)(find_wall(cube, cube->ray.wall_dist) * (double)texture->width);
	if (cube->ray.wall_side == 0 && cube->ray.raydirx > 0)
		tex_x = texture->width - tex_x - 1;
	if (cube->ray.wall_side == 1 && cube->ray.raydiry < 0)
		tex_x = texture->width - tex_x - 1;
	step = texture->height / lheight;
	tex_pos = (start - HEIGHT / 2 + lheight / 2) * step;
	cube->ray.start = start;
	cube->ray.end = end;
	while (start < end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		ft_memcpy(&cube->img->pixels[(cube->img->width * start + x) * 4], \
		&texture->pixels[(texture->width * tex_y + tex_x) * 4], 4);
		start++;
	}
}

double	find_wall(t_cub3d *cube, double wall_dist)
{
	double	wall_x;

	if (cube->ray.wall_side == 0)
		wall_x = cube->player.yppos + wall_dist * cube->ray.raydiry;
	else
		wall_x = cube->player.xppos + wall_dist * cube->ray.raydirx;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	paint_bg(t_cub3d	*cube, int x)
{
	int				i;
	unsigned int	floor;
	unsigned int	ceiling;

	i = -1;
	floor = hex_to_uint(cube->data.floor);
	ceiling = hex_to_uint(cube->data.ceiling);
	while (++i < HEIGHT)
	{
		if (i <= cube->ray.start)
			mlx_put_pixel(cube->img, x, i, ceiling);
		if (i >= cube->ray.end)
			mlx_put_pixel(cube->img, x, i, floor);
	}
}

unsigned int	hex_to_uint(char *hex)
{
	unsigned int	result;

	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			result = result * 16 + (*hex - '0');
		else if (*hex >= 'A' && *hex <= 'F')
			result = result * 16 + (*hex - 'A' + 10);
		hex++;
	}
	return (result);
}
