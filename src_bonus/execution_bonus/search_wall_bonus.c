/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:27:34 by dgross            #+#    #+#             */
/*   Updated: 2023/02/17 10:04:12 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	search_wall(t_cub3d *cube)
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
