/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:02:16 by dna               #+#    #+#             */
/*   Updated: 2023/02/09 18:11:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "cub3d.h"
#include "macros.h"
#include <math.h>
#include <stdio.h>

void	turn_right(t_cords *player)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos(-0.1) - player->ypdir * sin(-0.1);
	player->ypdir = tmp_dir_x * sin(-0.1) + player->ypdir * cos(-0.1);
	player->plane_x = player->plane_x * cos(-0.1) - player->plane_y * sin(-0.1);
	player->plane_y = tmp_plane_x * sin(-0.1) + player->plane_y * cos(-0.1);
}

void	turn_left(t_cords *player)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos(0.1) - player->ypdir * sin(0.1);
	player->ypdir = tmp_dir_x * sin(0.1) + player->ypdir * cos(0.1);
	player->plane_x = player->plane_x * cos(0.1) - player->plane_y * sin(0.1);
	player->plane_y = tmp_plane_x * sin(0.1) + player->plane_y * cos(0.1);
}

void	turn_mouse(t_cords *player, double rot)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos(rot) - player->ypdir * sin(rot);
	player->ypdir = tmp_dir_x * sin(rot) + player->ypdir * cos(rot);
	player->plane_x = player->plane_x * cos(rot) - player->plane_y * sin(rot);
	player->plane_y = tmp_plane_x * sin(rot) + player->plane_y * cos(rot);
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
	if (xpos == WIDTH / 2 && ypos == HEIGHT / 2)
		return ;
	if (xpos < WIDTH / 2)
	{
		angle = (xpos - WIDTH / 2);
		rot = (rot * (1 - 0.05) + (atan2(HEIGHT / 2, angle)) * 0.05);
	}
	if (xpos > WIDTH / 2)
	{
		angle = (xpos - WIDTH / 2);
		rot = -(rot * (1 - 0.05) + (atan2(HEIGHT / 2, angle)) * 0.05);
	}
	turn_mouse(player, rot);
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cube->mlx, WIDTH / 2, HEIGHT / 2);
}
