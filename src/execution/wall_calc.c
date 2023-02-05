/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:06:08 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 09:59:29 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <math.h>

double	calc_wall(t_cub3d *cube)
{
	double	wall_dist;

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
	}
	if (cube->ray.wall_side == 0)
		wall_dist = fabs((cube->ray.map_x - cube->player.xppos + (1 - cube->ray.stepx) / 2) / cube->ray.raydirx);
	else
		wall_dist = fabs((cube->ray.map_y - cube->player.yppos + (1 - cube->ray.stepy) / 2) / cube->ray.raydiry);
	return (wall_dist);
}
