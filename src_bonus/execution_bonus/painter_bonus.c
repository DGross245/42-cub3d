/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:39 by dgross            #+#    #+#             */
/*   Updated: 2023/02/19 13:11:33 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_bonus.h"
#include "MLX42.h"
#include "libft.h" // ft_memcpy

#include <math.h> // fabs floor

void	calc_wall(t_cub3d *cube)
{
	int		start;
	int		end;

	if (cube->ray.wall_side == 0)
	{
		cube->ray.wall_dist = fabs((cube->ray.map_x - cube->player.xppos \
		+ (1 - cube->ray.stepx) / 2) / cube->ray.raydirx);
	}	
	else
	{
		cube->ray.wall_dist = fabs((cube->ray.map_y - cube->player.yppos \
		+ (1 - cube->ray.stepy) / 2) / cube->ray.raydiry);
	}
	cube->ray.lheight = (int)cube->mlx->height / cube->ray.wall_dist;
	start = -cube->ray.lheight / 2 + cube->mlx->height / 2;
	end = cube->ray.lheight / 2 + cube->mlx->height / 2;
	if (start < 0)
		start = 0;
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
	double	texel_step;
	int		i;

	tex_x = find_x_pos(cube, texture);
	texel_step = texture->height / cube->ray.lheight;
	tex_pos = (cube->ray.start - cube->mlx->height \
	/ 2 + cube->ray.lheight / 2) * texel_step;
	i = cube->ray.start - 1;
	while (++i < cube->ray.end)
	{
		tex_y = (int)tex_pos % texture->height;
		ft_memcpy(&cube->img->pixels[(cube->img->width * i + x) \
		* 4], &texture->pixels[(texture->width * tex_y + tex_x) * 4], 4);
		tex_pos = tex_pos + texel_step;
	}
}

int	find_x_pos(t_cub3d *cube, mlx_texture_t	*texture)
{
	double	wall_hit;
	int		tex_x;

	if (cube->ray.wall_side == 0)
		wall_hit = cube->player.yppos + cube->ray.wall_dist * cube->ray.raydiry;
	else
		wall_hit = cube->player.xppos + cube->ray.wall_dist * cube->ray.raydirx;
	tex_x = (int)((wall_hit - floor(wall_hit)) * texture->width);
	if ((cube->ray.wall_side == 0 && cube->ray.raydirx > 0)
		|| (cube->ray.wall_side == 1 && cube->ray.raydiry < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	paint_bg(t_cub3d	*cube, int x)
{
	int	i;

	i = -1;
	while (++i < cube->mlx->height)
	{
		if (i < cube->ray.start + 1)
			mlx_put_pixel(cube->img, x, i, cube->data.ceiling);
		else if (i > cube->ray.end - 1)
			mlx_put_pixel(cube->img, x, i, cube->data.floor);
	}
}

unsigned int	hex_to_uint(char *hex)
{
	unsigned int	result;
	int				i;

	i = -1;
	while (hex[++i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			result = result * 16 + (hex[i] - '0');
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result = result * 16 + (hex[i] - 'A' + 10);
	}
	return (result);
}
