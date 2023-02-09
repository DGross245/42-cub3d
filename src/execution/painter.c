/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/09 16:27:59 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <macros.h>

void	calc_rest(t_cub3d *cube)
{
	int		start;
	int		end;

	if (cube->ray.wall_side == 0)
		cube->ray.wall_dist = fabs((cube->ray.map_x - cube->player.xppos \
		+ (1 - cube->ray.stepx) / 2) / cube->ray.raydirx);
	if (cube->ray.wall_side == 1)
		cube->ray.wall_dist = fabs((cube->ray.map_y - cube->player.yppos \
		+ (1 - cube->ray.stepy) / 2) / cube->ray.raydiry);
	cube->ray.lheight = (int)cube->mlx->height / cube->ray.wall_dist;
	start = (-cube->ray.lheight) / 2 + cube->mlx->height / 2;
	if (start < 0)
		start = 0;
	end = cube->ray.lheight / 2 + cube->mlx->height / 2;
	if (end >= cube->mlx->height)
		end = cube->mlx->height - 1;
	cube->ray.start = start;
	cube->ray.end = end;
}

void	painter(t_cub3d *cube, mlx_texture_t *texture, int x)
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		i;

	tex_x = find_wall(cube, texture);
	step = texture->height / cube->ray.lheight;
	tex_pos = (cube->ray.start - cube->mlx->height \
	/ 2 + cube->ray.lheight / 2) * step;
	i = cube->ray.start;
	while (i < cube->ray.end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		ft_memcpy(&cube->img->pixels[(cube->img->width * i + x) \
		* 4], &texture->pixels[(texture->width * tex_y + tex_x) * 4], 4);
		i++;
	}
}

int	find_wall(t_cub3d *cube, mlx_texture_t	*texture)
{
	double	wall_x;
	int		tex_x;

	if (cube->ray.wall_side == 0)
		wall_x = cube->player.yppos + cube->ray.wall_dist * cube->ray.raydiry;
	else
		wall_x = cube->player.xppos + cube->ray.wall_dist * cube->ray.raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if (cube->ray.wall_side == 0 && cube->ray.raydirx > 0)
		tex_x = texture->width - tex_x - 1;
	if (cube->ray.wall_side == 1 && cube->ray.raydiry < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	paint_bg(t_cub3d	*cube, int x)
{
	int				i;

	i = -1;
	while (++i < cube->mlx->height)
	{
		if (i <= cube->ray.start)
			mlx_put_pixel(cube->img, x, i, cube->data.ceiling);
		if (i >= cube->ray.end)
			mlx_put_pixel(cube->img, x, i, cube->data.floor);
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
