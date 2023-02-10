/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:55 by dgross            #+#    #+#             */
/*   Updated: 2023/02/10 13:30:24 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"

#include <math.h> // con sin atan2

void	turn(t_cords *player, double angle)
{
	double	tmp_dirx;
	double	tmp_plane_x;
	double	sin_a;
	double	cos_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	tmp_dirx = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos_a - player->ypdir * sin_a;
	player->ypdir = tmp_dirx * sin_a + player->ypdir * cos_a;
	player->plane_x = player->plane_x * cos_a - player->plane_y * sin_a;
	player->plane_y = tmp_plane_x * sin_a + player->plane_y * cos_a;
}

void	mouse_position(t_cub3d *cube, t_cords *player)
{
	int32_t			xpos;
	int32_t			ypos;
	double			angle;
	double			rot;

	xpos = 0;
	ypos = 0;
	rot = 0;
	mlx_get_mouse_pos(cube->mlx, &xpos, &ypos);
	mlx_set_mouse_pos(cube->mlx, cube->mlx->width / 2, cube->mlx->height / 2);
	if (xpos == cube->mlx->width / 2 && ypos == cube->mlx->height / 2)
		return ;
	if (xpos < cube->mlx->width / 2)
	{
		angle = (xpos - cube->mlx->width / 2);
		rot = (rot * (1 - 0.05) + (atan2(cube->mlx->height / 2, angle)) * 0.06);
	}
	else if (xpos > cube->mlx->width / 2)
	{
		angle = (xpos - cube->mlx->width / 2);
		rot = -(rot * (1 - 0.05) + \
		(atan2(cube->mlx->height / 2, angle)) * 0.06);
	}
	turn(player, rot);
}
