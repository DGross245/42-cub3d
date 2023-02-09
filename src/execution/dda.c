/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:06:08 by dgross            #+#    #+#             */
/*   Updated: 2023/02/09 14:49:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <math.h>

void	dda(t_cub3d *cube)
{
	while (cube->ray.wall_hit == 0)
	{
		if (cube->ray.sidedis_x < cube->ray.sidedis_y)
		{
			cube->ray.wall_side = 0;
			cube->ray.sidedis_x += cube->ray.deltadisx;
			cube->ray.map_x += cube->ray.stepx;
		}
		else
		{
			cube->ray.wall_side = 1;
			cube->ray.sidedis_y += cube->ray.deltadisy;
			cube->ray.map_y += cube->ray.stepy;
		}
		if (cube->data.map[cube->ray.map_x][cube->ray.map_y] == '1')
			cube->ray.wall_hit = 1;
		else if (cube->data.map[cube->ray.map_x][cube->ray.map_y] == '2')
			cube->ray.wall_hit = 2;
		else if (cube->data.map[cube->ray.map_x][cube->ray.map_y] == '3')
			cube->ray.wall_hit = 3;
	}
}

mlx_texture_t	*is_door(t_cub3d *cube, mlx_texture_t *wall_tex)
{
	if (cube->ray.wall_hit == 2)
		return (cube->tex.door);
	if (cube->ray.wall_hit == 3)
		return (cube->tex.door_open);
	else
		return (wall_tex);
}
