/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 18:08:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"

void	painter(t_cub3d *cube, int wall_dist)
{
	int		wheight;
	int		start;
	int		end;

	wheight = (cube->dot.map_y + (1 - cube->dot.stepy) / 2) / wall_dist;
	start = -wheight / 2 + (cube->dot.map_y + (1 - cube->dot.stepy) / 2) / 2;
	end = wheight / 2 + (cube->dot.map_y + (1 - cube->dot.stepy) / 2) / 2;
	if (start < 0)
		start = 0;
	if (end >= (cube->dot.map_y + (1 - cube->dot.stepy) / 2))
		end = (cube->dot.map_y + (1 - cube->dot.stepy) / 2) - 1;
	mlx_put_pixel(cube->img, start, end, 0);
}
