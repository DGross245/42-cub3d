/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:06:08 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 15:08:00 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	find_wall(t_cub3d *cube)
{
	int	wall;

	while (cube->dot.wall_hit == 0)
	{
		if (cube->dot.sidedis_x < cube->dot.sidedis_y)
		{
			cube->dot.wall_side = 0;
			cube->dot.sidedis_x += cube->dot.deltadisx;
			cube->dot.map_x += cube->dot.stepx;
		}
		else
		{
			cube->dot.wall_side = 1;
			cube->dot.sidedis_y += cube->dot.deltadisy;
			cube->dot.map_y += cube->dot.stepy;
		}
		if (cube->data.map[cube->dot.map_x][cube->dot.map_y] > 0)
			cube->dot.wall_hit = 1;
	}
	if (cube->dot.wall_hit == 0)
		wall = cube->dot.sidedis_x - cube->dot.deltadisx;
	else
		wall = cube->dot.sidedis_y - cube->dot.deltadisy;
	return (wall);
}

void	get_wall(int wall_dist)
{
	return ;
}
