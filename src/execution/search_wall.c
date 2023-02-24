/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:06:08 by dgross            #+#    #+#             */
/*   Updated: 2023/02/17 16:13:23 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_wall(t_cub3d *cube)
{
	while (1)
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
			break ;
	}
}
